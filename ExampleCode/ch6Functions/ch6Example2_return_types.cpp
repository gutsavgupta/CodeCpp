/*
 * c++ function return type
 *
 * Declaring a function returning pointer to array of size N
 *
 * Direct Way
 * int (*func(int,int))[10]
 * func --> is function of arg (int, int) which
 *          return pointer to array of size [10]
 *          of type int
 *
 * Elegant way
 * declare type for array of int of size [10]
 * using arr10  = int[10];
 * typedef int (arr10)[10];
 *  
 *  arr10* func(int, int)
 *
 * declare array of size 100 of type pointer to function of arg(char, char) return double
 * Driect way
 *  double (*arrData[100])(char, char)
 * Elegant way
 *  using funcPtr = double (*(char,char))
 *
 */

#include <iostream>
#include <cstdlib>

#ifdef __DEBUG__
#define DEBUG(msg) (std::cout << __func__ << msg << std::endl)
#else
#define DEBUG(msg) (void)0
#endif

namespace Example2
{
    using funcPtr1   = double (*)(char,char);
    typedef double (*funcPtr2)(char,char);

    double myFunc1(char a, char b){ return (1.0*a + 2.1*b); }
    double myFunc2(char a, char b){ return (3.0*a + 4.0*b); }
    double myFunc3(char a, char b){ return (2.0*a + 4.5*b); }
    double myFunc4(char a, char b){ return (6.0*a + 7.3*b); }

    void test1()
    {
        DEBUG("--------------------------------");
        funcPtr1 ptr1 = myFunc1;
        funcPtr2 ptr2 = myFunc2;
        std::cout << ptr1('a','p') << std::endl;
        std::cout << ptr2('b','c') << std::endl;
    }

    void test2()
    {
        DEBUG("--------------------------------");
        // direct delaration of array //
        double (*arrData1[])(char, char) = {
            myFunc1,
            myFunc2,
            myFunc3,
            myFunc4
        };
    
        // better way to declare //
        funcPtr1 arrData2[] = {
            myFunc1,
            myFunc2,
            myFunc3,
            myFunc4
        };
        
        for(auto& funcPtrItr : arrData1)
        {
            std::cout << funcPtrItr('a','b') << std::endl;
        }

        for(auto& funcPtrItr : arrData2)
        {
            std::cout << funcPtrItr('b','a') << std::endl;
        }
    }

    /*
     * Using a Trailing Return Type
     *
     * Under the new standard, another way to simplify the declaration of func 
     * is by using a trailing return type. Trailing returns can be defined for 
     * any function, but are most useful for functions with complicated return types
     *
     * fcn takes an int argument and returns a pointer to an array of ten ints
     * auto func(int i) -> int(*)[10];
     *
     * Using decltype
     * As another alternative, if we know the array(s) to which our function 
     * can return a pointer, we can use decltype to declare the return type
     *
     * int odd[] = {1,3,5,7,9};
     * int even[] = {0,2,4,6,8};
     * returns a pointer to an array of five int elements
     * decltype(odd) *arrPtr(int i)
     * {
     *      return (i % 2) ? &odd : &even; // returns a pointer to the array
     * }
     *
     * declaration of function that return ref to an array of 10 string
     * 
     * std::string (&func(void))[10];           // normal way
     *
     * auto func(void)  ->  std::string (&)[10] // trailing return type
     *
     * std::String arr[10];
     *
     * decltype(arr)* func(void);
     *
     */ 
}

int main(int argc, const char* argv[])
{   
    // code //
    Example2::test1();
    Example2::test2();
    return EXIT_FAILURE;
}
