/* Class basics, c++ class introduction
 * this example will illustrate some important
 * basics to develop and declare and define a 
 * c++ class 
 * 
 * Advantages of having c++ classes
 * you can define many functionality related to
 * the object data like:
 * 1. ">>" or "<<" operator to input output data to obj.
 * 2. "++", "+=", "=" operator to inc, compund add ect..
*/
#include <iostream>

namespace tEXAMPLE4{
    // sales-item class build
    // purpose: to showcase:
    // 1. Total Revenue
    // 2. # of copies sold
    // 3. avg. sale price of a book
    class tSaleItem{
        private:
            std::string isbn;
            std::string name;
            double  pric;
            int     qnty;
        
        public:
            std::string getIsbn(){ 
                return isbn; 
            }

            friend std::istream &operator>>( std::istream &inp, tSaleItem &obj){
                inp >> obj.isbn >> obj.name >> obj.qnty >> obj.pric;
                return inp;
            }

            friend std::ostream &operator<<( std::ostream &out, const tSaleItem &obj){
                out << "ISBN number\t\t: "  << obj.isbn << std::endl;
                out << "Book name\t\t: "    << obj.name << std::endl;
                out << "Book price\t\t: "   << obj.pric << std::endl;
                out << "Book quantity\t\t: "<< obj.qnty << std::endl;
                out << "Total Price\t\t: "  << (obj.pric*obj.qnty) << std::endl;
                return out; 
            }
            
               
    };
    
} 

/* This code contains << and >> operator overloaded 
 * 1. code dosen't handles invalid input (TODO)
 * 2. code dosen't support +,+= operator error handles
*/

int main(int argc, char const *argv[]){
    /* code */
    tEXAMPLE4::tSaleItem items[5];

    // Input help //
    std::cout << "Please enter 5 input in following format: " << std::endl;
    std::cout << "<ISBN> <BOOK_NAME> <QTY> <PRICE>" <<std::endl;

    for(int i=0; i<5; i++){
        std::cin >> items[i];
    }
    for(int i=0; i<5; i++){
        std::cout << items[i] << std::endl;
    }
    return 0;
}
