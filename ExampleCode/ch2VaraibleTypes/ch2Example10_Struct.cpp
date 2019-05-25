/* This Example is to understand basics of struct
 * in c++ standards which are/may be different from
 * c standards
 * 
 * struct has default and parameterize intializer in the
 * definiton of itself
*/
#include <iostream>

namespace tEXAMPLE10{

    // testing with simple struct
    struct SalesData{
        std::string     name;
        unsigned int    qnty;
        double          rate;

        #if 1
        SalesData():
        name(""),
        qnty(0),
        rate(0.0){}
        #endif

        SalesData(std::string nm, unsigned int qt, double rt):
        name(nm),
        qnty(qt),
        rate(rt){}

        void printData(){

            std::cout << "Product Name: " << name << " :: ";
            std::cout << "Product Qnty: " << qnty << " :: ";
            std::cout << "Product Rate: " << rate << std::endl;
        }
    };

    void test1(){

        // using default intializer //
        SalesData data1;            // if only parameterize constructor is defined
                                    // then it will throw the error
        data1.printData();
    }
}

int main(int argc, char const *argv[]){

    // Functionaily test
    for( int i=0; i<2; i++){
        std::string name("Product");
        tEXAMPLE10::SalesData data(name, i, i*3.45);
        data.printData();
    }

    // Scope funtions 
    tEXAMPLE10::test1();
    
    return 0;
}
