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
T* myBeg(T (*arr)[N])
{
    return static_cast<T*>(&(*arr)[0]);
}

template<typename T, std::size_t N>
T* myEnd(T (*arr)[N])
{
    return static_cast<T*>(&(*arr)[N]);
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
    printArr(utility::myBeg(&Arr), utility::myEnd(&Arr));
}

}

int main(int argc, const char* argv[])
{
    /**put you code here**/
    function::func1();
    function::func2();

    return 0;
}
