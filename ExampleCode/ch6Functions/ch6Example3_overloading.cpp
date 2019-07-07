/* 
 * overloading in cpp
 * Overloaded functions must differ in the number or the type(s) of their parameters
 * It is an error for two functions to differ only in terms of their return types. If the
 * parameter lists of two functions match but the return types differ, then the second
 * declaration is an error:
 *
 * A parameter that has a top-level const is indistinguishable 
 * from one without a top-level const:
 *  Record lookup(Phone);
 *  Record lookup(const Phone);   // redeclares Record lookup(Phone)
 *
 *  while low-level const are different story
 *  we can distinguish function based on param of pointer/refs
 *  to const or non-const type
 *
 *  Record lookup(Account&);       // function that takes a reference to Account
 *  Record lookup(const Account&); // new function that takes a const reference
 *
 * The compiler can use the constness of the argument to distinguish
 * which function to call. Because there is no conversion from const,
 * we can pass a const object (or a pointer to const) only to the version with a
 * const parameter. Because there is a conversion to const, we can call either
 * function on a nonconst object or a pointer to nonconst. However, as we’ll see 
 * the compiler will prefer the nonconst versions when we pass a nonconst object 
 * or pointer to nonconst
 *
 * const_cast and Overloading
 * we noted that const_casts are most useful in the context of overloaded functions
 * const_cast can exploit low-level const
 *
 * string &shorterString(string &s1, string &s2)
 * {
 *      auto &r = shorterString(const_cast<const string&>(s1), 
 *                              const_cast<const string&>(s2));
 *      return const_cast<string&>(r);
 * }
 *
 * here cons_cast changes the <srting&> to <const string&>
 * and again changes <const string&> --> <sting&>
 *
 * Note: const_cast althoug cannot change const string& --> string or const string
 */

#include <iostream>

void print(int a)
{
    std::cout << "print int \tis called" << std::endl;
}

void print(double d)
{
    std::cout << "print double \tis called" << std::endl;
}

void print(std::string a)
{
    std::cout << "print string \tis called" << std::endl;
}

void print(std::string& a)
{
    std::cout << "print string ref \tis called" << std::endl;
}

namespace Example3
{
    /*
     * As usual, if we declare a name in an inner scope, that 
     * name hides uses of that name declared in an outer scope. 
     * Names do not overload across scopes
     * 
     * When we call print, the compiler first looks for a 
     * declaration of that name. It finds the local declaration 
     * for print that takes an int. Once a name is found, the compiler 
     * ignores uses of that name in any outer scope. Instead, the 
     * compiler assumes that the declaration it found is the one 
     * for the name we are using. What remains is to see if the use 
     * of the name is valid
     *
     * In C++, name lookup happens before type checking
     */ 
    
    void print()
    {
        std::cout << "print2 called" << std::endl;
    }

    void test1()
    {
        std::string a = "hello";
        void ::print(int);    // in test scope declares print(int) only
        ::print("value");   // global scope print is used
        ::print(10);        // global scope ptiny int is used
        ::print(3.2);       // global scope print double is used
        // print(2.4);         // undefined print int ref is used
    }

}

int main(int argc, const char* argv[])
{
    std::string str1{"hello"};
    
    // const_case<>
    auto &conv1 = const_cast<const std::string&>(str1);
    auto &conv2 = const_cast<std::string&>(conv1);

    // test function
    Example3::test1();
    return 0;
}
