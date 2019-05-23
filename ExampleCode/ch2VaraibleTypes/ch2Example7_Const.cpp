/* This example will help us to understand
 * basics of const in cpp and how compiler deals
 * with const declaration, intialization etc.. 
*/


/* This example explain the use of const type
 * and how to use it to achieve the disered goal
 * 
 * Note: 
 * 1. Const expression need to intialized when defined
 * 2. Const variable are by deafult local to file i.etc
 * one has to define the same const variable in other files
 * to use it.
 * 3. For local Const var, compiler usually replace the variable
 * with its corrosponding value in the code (initalizer)
 * 4. For extending the scope of const Var, const var should be declared
 * and defined using extern keyword with initalizer
 * 
 * EX:  // file.cpp, Defines and initalize a const that is accessible to other files
 *      extern const int buffsize = 512;
 *      // file.hpp, Uses the buffsize defined in file.cpp
 *      extern const int buffsize 
 * 
 * Note:
 * 1. You can change the const obj val, using the pointer application on the memory
 * 
*/

#include <iostream>

namespace tEXAMPLE7{

    void test1(){

        const int ci = 1024;
        const int &ri = ci;
        // ri = 512         // error, you cannot change const int
        // int &r2 = ci     // error, you cannot assign int reference to const int

        std::cout << "Adr of ci: " << &ci << std::endl;
        std::cout << "Val of ci: " << ci << std::endl;
        std::cout << "Val of ri: " << ri << std::endl; 
    }

    void test2(){

        // can we change the value of const int using pointer //
        const int ci    = 1024;
        const int *cpi  = &ci;
        int *pi = (int*)cpi;

        // print the curr val //
        std::cout << "Val of ci, cpi, *cpi: " << ci << "," << cpi << "," << *cpi << std::endl;
        std::cout << "Val of pi, *pi: " << pi << "," << *pi << std::endl;

        std::cout << "------------Modifying pi-----------" << std::endl;
        *pi = 512;
        // ci = 512;    // error
        // *cpi = 512;  // error

        std::cout << "Val of ci, cpi, *cpi: " << ci << "," << cpi << "," << *cpi << std::endl;
        std::cout << "Val of pi, *pi: " << pi << "," << *pi << std::endl;
    }

    void test3(){

        // exception of reference rule
        // refernce of const can be assigned non-const object of compatible type

        double dval     = 3.14;
        long long llval = 1000;

        // although base type of ri1 & dval aren  different
        // but compiler allow such kind of reference
        // reason being you are allowed to change the dval or llval
        // usinf ri1 or ri2;
        const int &ri1 = dval;
        const int &ri2 = llval;

        // lets check what can happen
        // proposal: compiler implements above condition as follows
        // int temp = dval;
        // const int &ri1 = temp;

        std::cout << "Val of ri1 & ri2: " << ri1 << " & " << ri2 << std::endl;
        std::cout << "Adr of ri1 & ri2: " << &ri1 << " & " << &ri2 << std::endl;
        std::cout << "Adr of dval & llval: " << &dval << " & " << &llval << std::endl;

        // changing the dval and llval
        std::cout << "---------Modifying dval & llval------------" << std::endl;
        dval    = 6.14;
        llval   = 3000;

        std::cout << "Val of ri1 & ri2: " << ri1 << " & " << ri2 << std::endl;
        std::cout << "Adr of ri1 & ri2: " << &ri1 << " & " << &ri2 << std::endl;
        std::cout << "Adr of dval & llval: " << &dval << " & " << &llval << std::endl;
    }
}

int main(int argc, char const *argv[]){

    tEXAMPLE7::test1();
    tEXAMPLE7::test2();
    tEXAMPLE7::test3();
    return 0;
}
