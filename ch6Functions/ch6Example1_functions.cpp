/*
 * return_type Function(args...)
 * {
 *      ..body..
 *      return type;
 * }
 *
 * Note: calling function does not garuntee the evaluation order
 *       of the arguments, compliers are free to evaluate the args
 *       in which order is better suited
 *
 *       parameters: are the variables that get initialized by the corrosponding args
 *       arguments: are the variables passed in the function to init parameters
 *
 *       atomatic object: are the object which get initialized when in scope after that
 *       their values are undefined
 *
 *       parameters are automatic object !!
 *       static variable in function
 *          > lifetime through out the program
 *          > initialized before calling the function
 *          > values retains but scope finished after the function
 *          > if no explicit initializer is specified
 *            then the variable get value-initalized (default constructor or '0')
 *
 * Note: Arrays are not passed by value, although you can pass the reference
 *       to an array of fixed size
 *
 *       void func( int (&arr)[10] );   // is function which takes ref to int arr[10] type
 *       void func( int arr[10] );      // useless, func take arg as int**
 *       void func( int *arr )          // same as above *
 *
 *       compiler ususally ignore first dimension i.e
 *       void func( int (*arr)[10] );   // pointer to array of 10 int
 *       void func( int arr[][10] ):    // this is same as above
 *          
 *          
 */

#include <iostream>
#include <string>
#include <vector>

namespace utility
{

// templated function to move
// c-types from one var to another
template<typename T>
void mySwap(T& A, T& B)
{
    T _temp = std::move(B);
    B       = std::move(A);
    A       = std::move(_temp);
}

template<typename T, std::size_t N>
T* myBeg(T (&arr)[N])
{
    return static_cast<T*>(&arr[0]);
}

template<typename T, std::size_t N>
T* myEnd(T (&arr)[N])
{
    return static_cast<T*>(&arr[N]);
}

} // namespace utility

namespace function
{

void func1()
{
    // testing for containers
    // supporting std::move
    std::cout << "testing for vector" << std::endl;
    std::vector<int> A{1,2,3,4};
    std::vector<int> B{5,6,7,8};
    
    utility::mySwap(A,B);
    for(const auto& a : A) { std::cout << a << " "; } std::cout << std::endl;
    for(const auto& b : B) { std::cout << b << " "; } std::cout << std::endl;

    // testing for primitive types
    std::cout << "testing for integers" << std::endl;
    long primA = 10, primB = 20;
    utility::mySwap(primA, primB);
    std::cout << primA << " " << primB << std::endl;
}


void func2()
{
    auto printArr = [](int* str, int* end)
    {
        while(str != end) std::cout << *str++ << std::endl;
    };

    int Arr[] = {1,2,3,4,5};
    printArr(utility::myBeg(Arr), utility::myEnd(Arr));
}
/*
 * We can pass varring number of args to function
 * using below three methods
 *
 * 1. Initializer_list  :   used for passing varrying number of
 *                          args of same type
 * 2. Variadic template :   will discuss later, but can be used to pass
 *                          varrying number of arguments of different
 *                          types
 * 3. ellipis parameter :   Old C-style way of passing varring number of
 *                          arguments
 *
 */

/*
 * initializer_list<>   :   represent arrays of same type of elements
 *                          has const copy of corresponding initializer
 *                          copying an initializer_list into other does
 *                          not copy the elements, elements b/w copies are
 *                          shared
 *
 * initializer_list<T> lst;
 * initializer_list<T> lst{a,b,c,d};
 *
 * lst2 = lst1
 * lst2(lst1)
 *
 * lst.size(), lst.begin(), lst.end()
 *
 */

void func3(std::initializer_list<std::string> lst)
{
    for(auto itr = lst.begin(); itr != lst.end(); itr++)
    {
        std::cout << *itr << "::"; 
    }   std::cout << std::endl;

    for(auto &wStr : lst)
    {
        // wStr = "none";   // as element of initializer_list are const
        std::cout << wStr << "::";
    }   std::cout << std::endl;
}

/*
 * ellipis parameter    :   Ellipsis parameters are in C++ to allow programs 
 *                          to interface to C code that uses a C library 
 *                          facility named varargs
 *
 * An ellipsis parameter may appear only as the last element 
 * in a parameter list and may take either of two forms:
 *      
 *      >   void foo(parm_list, ...);
 *      >   void foo(...);
 *
 */

/*
 * Note
 * Reference Returns Are Lvalues
 * Whether a function call is an lvalue (§ 4.1.1, p. 135) depends on the return type of
 * the function. Calls to functions that return references are lvalues; other return types
 * yield rvalues
 *
 * After the  assignment the temporary variable formed because of return
 * is destroyed
 *
 * In a function that returns a built-in type, a braced list may contain at 
 * most one value, and that value must not require a narrowing conversion
 *
 * Return from main
 * There is one exception to the rule that a function with a return type other than void
 * must return a value: The main function is allowed to terminate without a return. If
 * control reaches the end of main and there is no return, then the compiler implicitly 
 * inserts a return of 0.
 *
 * Machine independent return for main
 *
 * int main()
 * {
 *  if (some_failure)
 *      return EXIT_FAILURE;  // defined in cstdlib
 *  else
 *      return EXIT_SUCCESS;  // defined in cstdlib
 *
}
 */

struct foo
{
    int a,b;

    // consturtor //
    foo(): a(0), b(0) 
    {
        std::cout << "default_constructor" << std::endl;
    }

    foo(int a1, int b1): a(a1), b(b1)
    {
        std::cout << "param_constructor" << std::endl;
    }

    // copy constructor //
    foo(const foo& B)
    {
        std::cout << "copy consrtuctor" << std::endl;
        a = B.a;
        b = B.b;
    }

    foo(const foo&& B)
    {
        std::cout << "rvalue copy constructor" << std::endl;
        a = B.a;
        b = B.b;
    }
    
    // operator
    foo& operator=(const foo& B)
    {
        std::cout << "assignment operator called" << std::endl;
        a = B.a;
        b = B.b;
        return *this;
    }

    // destructor
    ~foo()
    {
        std::cout << "destrutor called" << std::endl;
    }

    // utility funct //
    void printx()
    {
        std::cout << a << "::" << b << std::endl;
    }
};

inline foo getNewFoo(int a, int b)
{
    foo foo2{a,b};
    std::cout << "addr::foo::" << &foo2 << std::endl;
    return foo2;
}

inline foo randomFunc(foo A)
{
    return A;
}

void func4()
{
    int a,b;
    
    // direct intialization //
    std::cout << "test1" << std::endl;
    std::cin >> a >> b;
    foo obj1{getNewFoo(a,b)};
    obj1.printx();
    std::cout << "addr::obj1::" << &obj1 << std::endl;

    // indirect initalizetion //
    std::cout << "test2" << std::endl;
    std::cin >> a >> b;
    foo obj2 = getNewFoo(a,b);
    obj2.printx();
    std::cout << "addr::obj2::" << &obj2 << std::endl;

    //  initalizetion //
    std::cout << "test3" << std::endl;
    std::cin >> a >> b;
    foo obj3; 
    obj3 = getNewFoo(a,b);
    obj3.printx();
    std::cout << "addr::obj3::" << &obj3 << std::endl;
    
    std::cout << "test4" << std::endl;
    foo obj4 = randomFunc(obj1);

    std::cout << "returnint" <<std::endl;
    return;
}

}

int main(int argc, const char* argv[])
{
    /**put you code here**/
    function::func1();
    function::func2();
    function::func3({"hello", "how", "are", "you"});
    function::func4();
    return 0;
}
