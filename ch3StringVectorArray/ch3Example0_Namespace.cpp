/* Namespace Example: Basic use and declaration 
 * Rules to use namespace::declaration from a namespace
 * 
 * 1. using namespaceT::funcName    // funcName, types, vars any other declaration becomes visible to the scope
 * 2. using namespaceT              // all funcName os namespaceT become visible
*/

#include <iostream>

namespace tEXAMPLE0
{
    // macro declaration
    #define _FETCH_STD(arg) std::cin  >> arg; 
    #define _WRITE_STD(arg) std::cout << arg;
    #define _FUNCT_IDP(arg) std::cout << "Exec <<" << __func__ << ">>" << std::endl;

    // using declaration
    using std::cin;
    using std::cout;
    using std::endl;

    bool test1()
    {
        _FUNCT_IDP(0)
        // code starts below //

        uint16_t a,b,c,d;
        std::string msg1("Input a, b, c, d: ");
        std::string msg2("Value a, b, c, d: ");

        cout << msg1 << endl;
        cin  >> a >> b >> c >> d ;

        cout << msg2 << endl;
        cout << a << " " << b << " " << c << " " << d << endl;
        
        return true;
    }

    bool test2()
    {
        _FUNCT_IDP(0)
        // code starts below //
        decltype(0x0ull) var1;
        decltype(0x0ull) var2;

        _FETCH_STD( var1 >> var2 )
        _WRITE_STD( "Testing var1 && var2:: " << var1 << " && " << var2 << "\n")

        return true;
    }
}

int main(int argc, const char *argv[])
{
    tEXAMPLE0::test1();
    tEXAMPLE0::test2();
    return 0;
}