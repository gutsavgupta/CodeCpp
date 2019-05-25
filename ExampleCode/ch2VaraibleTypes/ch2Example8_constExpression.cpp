/* This Example is illustrate the properties 
 * & use case of constExpression in c+ 
 * 
 * Definition: A constExpression is a expression whose value 
 *             can't change, and whose value can be calculated
 *             at compiled time
 * Note: 
 *          1. Literals are const expression 
 *          2. Const obj intiallzed from constExpression are constexpr
 *          3. c++11 standards allows us to define constepr function which can be 
 *             evaluated at compile time
 *          4. Type in const expression, compiler allowd literal types for constExpression
 *             literal types: arithmetic types, pointers & reference (classes, string are not literal types)
 *          5. constexpr pointer can point to obj whoes memory addr remains fixed
 *          6. local variable are not considered to be valid to be assinged to constexpr pointer as
 *             their addr can change in run time;
 * 
 * Usage:
 *          TODO              
 *
 */

#include <iostream>

namespace tEXAMPLE8{

    extern const int var1;
    int globalVar = 100;


    constexpr int func(){ return 20; }

    void test1(){

        const int varConstExpr = 0x00;                  // literals are const expression
        constexpr long lemda = varConstExpr + 23;       // const int initialized by constExpression are constExpression
        constexpr int lemda2 = varConstExpr + func();   // constexpr are constExpression
        // usage --> ??

        std::cout << "varConstExpr: " << varConstExpr << std::endl;
        std::cout << "lemda: " << lemda << std::endl;
        std::cout << "lemda2: " << lemda2 << std::endl;

        // constexpr int *ptr1 = &lemda2;               // constexpr ptr shoud contain addr which does not change in run time
                                                        // as constexpr value are caculated in compile time only
                                                        // therefore addr of local variables can be assigned to constxpr ptr
        
        // ptr1 and ptr2 can initialized as golbalVar and Var1 are
        // declared out of any function
        // pseduo-global scope
        constexpr int *ptr1 = &globalVar; 
        constexpr const int *ptr2 = &var1;

        std::cout << "Addr of globalVar: " << ptr1 << std::endl;
        std::cout << "Addr of var1: " << ptr2 << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    tEXAMPLE8::test1();
    return 0;
}
