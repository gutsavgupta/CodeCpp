/* Data variables and simple type casing 
 * Cpp data type and type cast are compiler 
 * dependent and should be learnt properly 
*/

#include <iostream>

namespace tEXAMLPE2
{
    /* Primitive data type supported in c++ 
     * int      :   4 byte
     * long     :   4 byte
     * long long:   8 byte
     * double   :   8 byte
     * float    :   4 byte
     * char     :   1 byte
     * short    :   2 byte
    */

    void test1()
    {
        int         a = 0x10;
        long        b = 0xff;
        long long   c = 0xffffaaaaffffaaaa;
        short int   d = 0xffaa;

        std::cout << "Printing a: " << a << std::endl;
        std::cout << "Printing b: " << b << std::endl;
        std::cout << "Printing c: " << c << std::endl;
        std::cout << "Printing d: " << d << std::endl;
    }
} // namespace tEXAMLPE2


int main()
{
    // call the test function //
    tEXAMLPE2::test1();
    return 0;
}
