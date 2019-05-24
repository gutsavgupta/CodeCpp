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
 * 2. You can reference a reference only reference rule should be applied
 * 3. for leading const pointer expression start from right to left
 *      for ex:
 *      int const * const *ppi;
 *      1. ppi is a pointer
 *      2. ppi is a pointer to const pointer
 *      3. ppi is a pointer to const pointer to const int
 * 4. To expand the scope of const variable, we should use extern
 *    while defining the const variable  
 *      EX: const int var1 = 10;        // limit the scope local to file
 *          extern const int var1 = 10; // expand the scope of var1 across files
 * 
 * 5. const reference can accpet the rvalue expression (by the way assignment is implemented)
 * 
 * IMPORTANT POINT TO LOOK AT
 * 1. Check whether const obj are intializing or Note
 * 2. pointer to const obj doesn't require initalizer as ptr is not const
 * 3. non-const pointer or non-const refernce can point or intialized with const obj
 * 4. const reference can be initialized with r-value
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
        int const &ri1 = dval;
        int const &ri2 = llval;

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

    void test4(){

        int a = 10;
        int &ar = a;
        int &arr = ar;
        std::cout << &a << " " << &ar << " " << &arr << std::endl;
    }

    // declaring the constant int var1 //
    extern const int var1;

    void test5(){

        // testing the scope of var1 //
        std::cout << var1 << std::endl;

    }

}

int main(int argc, char const *argv[]){

    #if 0
    tEXAMPLE7::test1();
    tEXAMPLE7::test2();
    tEXAMPLE7::test3();
    tEXAMPLE7::test4();
    #endif
    tEXAMPLE7::test5();
    return 0;
}

