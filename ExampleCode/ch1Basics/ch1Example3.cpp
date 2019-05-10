/* This example gives intro to iostream in c++
 * c++ provide iostream library to handle I/O operation 
 * in c++, iostream comprises of two main library
 * 
 * 1. istream --> input stream
 * 2. ostream --> output stream
 * 
 * stream provided from input
 * 1. cin
 * 
 * stream provided from output
 * 1. cout -> standard output
 * 2. cerr -> standard error
 * 3. clog -> standard logs
 * 
 * Two major concept to understand
 * how '<<' and '>>' output & input
 * operators
 * ans:: std library defines the behaviour
 * of each operator to handle diff - diff
 * data type 
 * like--> int, char, double, string
*/

#include <iostream>

namespace tEXAMPLE3
{
    void test1()
    {
        std::cout << "Executing test1()::" << std::endl;
        // input output testing //
        int a, b;
        std::cin >> a >> b ;
        std::cout << (a+b) << std::endl;
        /* Note:    endl is a special value called as manipulator
         *          serves two purposes
         *          1. end the current line
         *          2. flushing the buffer to related ostream
        */
    }

    void test2()
    {
        std::cout << "Executing test2()::" << std::endl;
        std::cout << "/*" << std::endl;
        std::cout << "*/" << std::endl;
        std::cout << /* "*/"/*"/*"*/ << std::endl;
    }

    void test3()
    {
        std::cout << "Executing test3()::" << std::endl;
        // handling indefinite input //
        int sum = 0;
        int val = 0;
        while(std::cin >> val){ sum += val; }
        std::cout << "Sum of all the nums: " << sum << std::endl;
        /** Note::  when using istream as condition, it evaluates:
         *          if istream is valid state: true
         *          if istream is invalid state: false
         *          Invalid state can occur when EOF arrived
         *          or invalid input for conversion
        */
    }

    void test4()
    {
        std::cout << "Executing test4()::" << std::endl;
        std::string tmp = "";
        std::string res = "";
        while(std::cin >> tmp){res.append(tmp);}
        std::cout << "The final statement:" << std::endl;
        std::cout << res << std::endl;
        /** Note::  The console input can simulate
         *          EOF by following input  
         *          Windows: [^Z] ctrl+Z
         *          Linux: [^D] ctrl+D
         */
    }

    void test5()
    {
        std::cout << "Executing test5()::" << std::endl;
        double temp; 
        
        std::cin >> temp;       // first extraction //
        std::cout << "decimal conversion: " << temp << std::endl;
        std::cin >> temp;       // second extraction //
        std::cout << "decimal conversion: " << temp << std::endl;

    }

    void test6()
    {
        // std::cerr testing //
        // TODO //
    }

};



int main(int argc, char const *argv[])
{
    
    tEXAMPLE3::test1();
    tEXAMPLE3::test2();
    tEXAMPLE3::test3();
    tEXAMPLE3::test4();
    tEXAMPLE3::test5();
    return 0;
}
