/*
 * The fundamental ideas behind classes are data abstraction and encapsulation.
 * 
 * Data abstraction : is a programming (and design) technique that relies on the
 *                    separation of interface and implementation. 
 * Interface        : The interface: of a class consists of the operations that 
 *                    users of the class can execute. 
 * Implementation   : The implementation includes the class’ data members, the 
 *                    bodies of the functions that constitute the interface, and 
 *                    any functions needed to define the class that are not intended 
 *                    for general use
 *
 * Encapsulation    : enforces the separation of a class’ interface and implementation. 
 *                    A class that is encapsulated hides its implementation—users of the 
 *                    class can use the interface but have no access to the implementation
 *
 */

#include <MyExecption.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace classes
{

class SaleItem
{
    public:
        SaleItem(const char* msg): except(msg) {}        

        void testException() const{ throw except; };

    private:
        const myexcept::exception except;
};

}  // namespace classes

int main(int argc, const char* argv[])
{
    classes::SaleItem s1("SaleItem 's1' exeception throw");
    try
    {
        s1.testException();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
