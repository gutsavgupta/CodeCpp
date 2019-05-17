/* This example will illustrate various data types 
 * and variable related information attached with
 * using c++ efficently
*/

#include <iostream>
#include <limits>

namespace tEXAMPLE1
{
    void test1()
    {
        /* Primitive data types and their size 
         * bool     : 1 byte    (8)
         * char     : 1 byte    (8)
         * wchar_t  : 2 byte    (16)
         * char16_t : 2 byte    (16)
         * char32_t : 4 byte    (32)
         * short    : 2 byte    (16)
         * int      : 4 byte    (32)
         * long     : 4 byte    (32)
         * long long: 8 byte    (64)
         * float    : 4 byte    (32)
         * double   : 8 byte    (64 bits)
         * long double: 16 byte (128 bits)
        */

        std::cout << "Executing test1()" << std::endl;
        std::cout << "size of bool\t\t: " << sizeof(bool) << std::endl;
        std::cout << "size of char\t\t: " << sizeof(char) << std::endl;
        std::cout << "size of wchar_t\t\t: " << sizeof(wchar_t) << std::endl;
        std::cout << "size of char16_t\t: " << sizeof(char16_t) << std::endl;
        std::cout << "size of char32_t\t: " << sizeof(char32_t) << std::endl;
        std::cout << "size of short\t\t: " << sizeof(short) << std::endl;
        std::cout << "size of int\t\t: " << sizeof(int) << std::endl;
        std::cout << "size of long\t\t: " << sizeof(long) << std::endl;
        std::cout << "size of long long\t: " << sizeof(long long) << std::endl;
        std::cout << "size of float\t\t: " << sizeof(float) << std::endl;
        std::cout << "size of double\t\t: " << sizeof(double) << std::endl;
        std::cout << "size of long double\t: " << sizeof(long double) << std::endl;
        std::cout << "size of long long*\t: " << sizeof(long long*) << std::endl;
        std::cout << "size of long double*\t: " << sizeof(long double*) << std::endl;
        std::cout << "size of int*\t\t: " << sizeof(int*) << std::endl; 
    }

    void test2()
    {
        std::cout << "Executing test2()" << std::endl;

        std::cout << "Min Int\t\t: " << std::numeric_limits<int>::min() << std::endl;               // int numeric limits 
        std::cout << "Max int\t\t: " << std::numeric_limits<int>::max() << std::endl;

        std::cout << "Min long long\t: " << std::numeric_limits<long long>::min() << std::endl;     // long long numeric limits 
        std::cout << "Max long long\t: " << std::numeric_limits<long long>::max() << std::endl;

        std::cout << "Min long double\t: " << std::numeric_limits<long double>::min() << std::endl; // long double numeric limits 
        std::cout << "Max long double\t: " << std::numeric_limits<long double>::max() << std::endl;

        std::cout << "Min double\t: " << std::numeric_limits<double>::min() << std::endl;           // double numeric limits 
        std::cout << "Max double\t: " << std::numeric_limits<double>::max() << std::endl;

        std::cout << "Min float\t: " << std::numeric_limits<float>::min() << std::endl;           // double numeric limits 
        std::cout << "Max float\t: " << std::numeric_limits<float>::max() << std::endl;
    }   
}

int main(int argc, char const *argv[])
{
    tEXAMPLE1::test1();
    tEXAMPLE1::test2();
    return 0;
}
