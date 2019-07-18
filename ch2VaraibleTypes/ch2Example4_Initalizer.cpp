/* This example is to explore initializer properties in c++ 
 * Note:    initializer and assignment are different conecpt 
 *          often used interchangebly
 * 
 * 1. List initializer: initalizing object using  "{}" curly braces
 *    Properties : 1. compiler doesn't allow initalizing if the data trucation
 *                    is happenning
 * 
 *    Example:
 *              int quantity = 1;
 *              int quantity = {1};
 *              int quantity{1};        // list initializer
 *              int quantity(1)         // non list initializer
*/

#include <iostream>

namespace tEXAMPLE4{

    void test1()
    {
        // valid ways of initalizing
        // find difference between "initalizing vs assignment"

        int var1 = 1;           // normal assignment
        int var2 = {1};         // using list initializer
        int var3{1};            // using list initializer
        int var4(1);            // ??

        std::cout << "var1: " << var1 << std::endl;
        std::cout << "var2: " << var2 << std::endl;
        std::cout << "var3: " << var3 << std::endl;
        std::cout << "var4: " << var4 << std::endl;
    }

    void test2(){

                                    // Note: data trucation is not allowed in list initializer
        const int a1(2.0);          // const int a1{2.0} --> invalid statement
        const int b1{12};

        std::cout << "a1 & b1 respc: " << a1 << " & " << b1 << std::endl;
    }

    void test3(){

        double wage;
        double salary = wage = 10.0;
        std::cout << "salary and wages: " << salary << " & " << wage << std::endl;
    }

    void test4(){

        // Decleration vs Definition
        // Decleration: make the name known to the file or scope of compilation
        // Definiton:   make the entity real or allocate functionality, presence or memory
        // keyword "extern" is used to declare without defining data type

        // extern int i;   // only declares it
        int i = 100;    // defines i and assign 100
        int a = 10;     // declares & defines a
        std::cout << "Value of i & a: " << i << " & " << a << std::endl;
    }
}


int main(int argc, char const *argv[]){

    tEXAMPLE4::test1();
    tEXAMPLE4::test2();
    tEXAMPLE4::test3();
    return 0;
}
