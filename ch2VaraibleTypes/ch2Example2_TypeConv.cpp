/* Type Converstion tutorial 
 * We will try to explore how does
 * complier perform type Conversion
 * for various type Conversion statements 
 * 
 * Note:    rule 1. Between signed, unsigned complier converts the variable type to unsigned
 *                  int a, unsigned int b, (a*b) --> unsigned
 *                  auto c = (a*b), Type(c) --> unsigned int
 * 
 *          rule 2. Data Type conversion: if auto conversion is supported by compiler for two data type
 *                  then smaller size data type is converted to larger size data type
 *                  char --> int --> long long --> float --> double --> long double
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

    void test3(){

        unsigned int a = 32;
        unsigned int b = 10;

        std::cout << "b - a: " << b - a << " int version: " << (int)(b - a) << std::endl; 
    }

    void test4(){
        
        unsigned char a = 250;
        int  b = 10;
        auto c = (a+b);
        std::cout << "The value of c: " << c << " Size of c: " << sizeof(c) << std::endl;

        long long x = 30LL;
        double y = 3.125;
        auto z = x+y;
        auto w = x*y;

        std::cout << "The value of z: " << z << " Size of z: " << sizeof(z) << std::endl;
        std::cout << "The value of w: " << w << " Size of w: " << sizeof(w) << std::endl;

        auto letsee = 3.14e1L;          // type of 3.14e1L is long double -> 16 Byte::128 biclearts
        std::cout << "The value of letsee: " << letsee << " Size of letsee: " << sizeof(letsee) << std::endl;

    }    
}

int main(int argc, char const *argv[]){

    tEXAMPLE2::test1();
    tEXAMPLE2::test2();
    tEXAMPLE2::test3();
    tEXAMPLE2::test4();
    return 0;
}
