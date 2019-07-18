/* In this example we will try to
 * look into the different scope (global & local)
 * how to override the identifier within different scope
 * how to call variable with same name but different scope
*/

#include <iostream>

// global variable for all Scope
int var1{100};
int var2{200};

namespace tEXAMPLE5{
    
    // global variable //
    int var1{10};
    int var2{20};

    void test1(){

        // declaring the outer scope //
        int var1 = 1;
        int var2 = 2;

        std::cout << "Local values of var1 & var2: " << var1 << " " << var2 << std::endl;
        std::cout << "tExample::Global values of var1 & var2: " << tEXAMPLE5::var1 << " " << tEXAMPLE5::var2 << std::endl;
        std::cout << "Global variable var1 & var2: " << ::var1 << " " << ::var2 << std::endl;
    }

    void test2(){

        // Scope overriding
        // TODO: how to resolve scope overriding in case of
        // multiple local scope 
        int i = 100, sum = 0;
        for(int i=0; i<10; i++){

            sum += i;
        }
        std::cout << sum << "::" << i <<std::endl;
    }

}

int main(int argc, char const *argv[]){
    
    tEXAMPLE5::test1();
    tEXAMPLE5::test2();
    return 0;
}
