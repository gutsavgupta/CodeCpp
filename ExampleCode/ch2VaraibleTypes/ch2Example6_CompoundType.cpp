/* This example wil based on compount types in c++
 * We will manily look into two main compount types
 * References & Pointer 
 * 
 * Note: 
 * 1. Reference variable has to be intialized with object of same types
 * 2. Once intialized, references does not refer to other object during lifetime
 * 3. Object and address and Reference address are same.
 * 
 * Note:
 * 1. Pointers (like references) used for indirect access to object
 * 2. Pointers are object whoes value points to the address of obj.
 * 3. Pointers can be used to access diff-diff obj. during their lifetime
 * 4. Pointers can be declared without initalization
 * 5. C++11 introduces nullptr literal for pointers, take cares of type of ptr
 * 
 * Note:
 * "*" , "&" are type modifier, hence it modifies the type of variable
 * but does not affect the base type.
 * 
 * int* a, b; here a is a pointer, b is int variable (misleading)
 * 
 */

#include <iostream>

namespace tEXAMPLE6{

    void test1(){

        int i = 0, &r1 = i;
        double d = 3.14, &r2 = d;

        r2 = 3.14;                      // valid references are can treated as normal variable, 
        std::cout << d << std::endl;    // d = 3.14
        
        r2 = r1;                        // changing value of d to 0.0
        std::cout << d << std::endl;    // d =  0.0

        i = r2;
        std::cout << r1 << std::endl;   // r1 will 0, as i is 0

        r1 = d;
        std::cout << i << std::endl;    // i will be 0 as, r1 is assigned zero value

        // lets check the address of both of them
        std::cout << "address of i : " << &i << std::endl;  // let say addr i --> 0x66fddc
        std::cout << "address of r1: " << &r1 << std::endl; // then the &r1 --> 0x66fddc
    }

    void test2(){

        // pointers
        int *pi = nullptr, i = 10;
        double *di = nullptr, d = 3.14;

        // pi = &d;         // Invalid statement, assigning double * to int*
        pi = (int*)&d;      // Type casting it to (int *) will work
        std::cout << "pi and *pi : " << pi << " " << *pi << std::endl;
        std::cout << "&d and d : " << &d << " " << d << std::endl;

        pi = &i;
        di = &d;
        std::cout << "pi and *pi : " << pi << " " << *pi << std::endl;
        std::cout << "di and *di : " << di << " " << *di << std::endl;

        long double j = 100, *li = &j;    // declaration and initalization
        std::cout << "size of li and *li : " << sizeof(li) << " " << sizeof(*li) << std::endl;

        // manually assigning value to pointers //
        pi = (int *)0x066fdc8;      // We have to typecast the value to (int*)
        // pi = 0x335566fdc8        // as literals are treated as int
    }

    void test3(){

        bool comp = (NULL == nullptr);
        std::cout << comp << std::endl;

        void * voidPtr;
        int i = 10; long long li = 10000; double d = 2.14;

        voidPtr = &i;
        voidPtr = &li;
        voidPtr = &d;

        std::cout << "Print voidPtr and voidPtr+1: " << voidPtr << " " << voidPtr+1 << std::endl;
    }

    void test4(){

        int i = 10; int *pi = &i; int **ppi = &pi;      // pointer to pointer
        int m = 20; int *pm = &m; int *&rpm = pm;       // reference to pointer
        int **&rppi = ppi;                              // reference to pointer to pointer
        // int* ni, &r = ni;                            // Invalid declaration

    }
}

int main(int argc, char const *argv[]){
    
    tEXAMPLE6::test1();
    tEXAMPLE6::test2();
    tEXAMPLE6::test3();
    return 0;
}
