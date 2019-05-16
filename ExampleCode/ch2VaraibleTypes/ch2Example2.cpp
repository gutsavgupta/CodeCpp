/* Type Converstion tutorial 
 * We will try to explore how does
 * complier perform type Conversion
 * for various type Conversion statements 
*/
#include <iostream>

namespace tEXAMPLE2{

    void test1(){

        //simple type Conversion
        int a   = -2.5;         // converts it to -2, removes the decimal part
        int b   =  2.5;         // converts it to 2, removes the deciaml part

        std::cout << "Type conversion of -2.5 to int a: " << a << std::endl;
        std::cout << "Type conversion of -2.5 to int b: " << b << std::endl;
    }

    void test2(){

        // check signed, unsigned type conversion
        int a           = -40;     // 32 bits repretation: 0xffffffc8
        unsigned int b  =  1;      // 32 bits repretation: 0x00000001

        std::cout << "unsigned a + b: " << (a+b) << std::endl;
        std::cout << "multiply a * b: " << (a*b) << std::endl;
    }

    void test3()
    {
        unsigned int a = 32;
        unsigned int b = 10;

        std::cout << "b - a: " << b - a << " int version: " << (int)(b - a) << std::endl; 
    }    
}

int main(int argc, char const *argv[]){

    tEXAMPLE2::test1();
    tEXAMPLE2::test2();
    tEXAMPLE2::test3();
    return 0;
}
