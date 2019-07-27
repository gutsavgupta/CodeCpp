/*
 * C++ constructor revisited
 *
 * NOTE: When we define variables, we typically initialize them immediately 
 *       rather than defining them and then assigning to them, Exactly the 
 *       same distinction between initialization and assignment applies to 
 *       the data members of objects. If we do not explicitly initialize a 
 *       member in the constructor initializer list, that member is default 
 *       initialized before the constructor body starts executing
 *
 * NOTE: Members that are const or references must be initialized. Similarly, 
 *       members that are of a class type that does not define a default 
 *       constructor also must be initialized
 *
 *       For Example:
 *       class ConstRef {
 *          public:
 *              ConstRef(int ii);
 *          private:
 *               int i;
 *               const int ci;
 *               int &ri;
 *           };

 *        // error: ci and ri must be initialized
 *        ConstRef::ConstRef(int ii)
 *        {              // assignments:
 *             i = ii;   // ok
 *             ci = ii;  // error: cannot assign to a const
 *             ri = i;   // error: ri was never initialized
 *        }
 *
 * NOTE: We must use the constructor initializer list to provide values for 
 *       members that are const, reference, or of a class type that does not 
 *       have a default constructor.
 *
 *       In general if a class member can be initialized in constructor we shall
 *       try to do it.
 *
 * NOTE: The constructor initializer list specifies only the values used to initialize 
 *       the members, not the order in which those initializations are performed. 
 *
 *       Members are initialized in the order in which they appear in the class definition: 
 *       The first member is initialized first, then the next, and so on. The order in which 
 *       initializers appear in the constructor initializer list does not change the order 
 *       of initialization
 *       
 *       It is a good idea to write constructor initializers in the same order as the members 
 *       are declared. Moreover, when possible, avoid using members to initialize other members.
 *      
 * NOTE: A constructor that supplies default arguments for all its parameters also 
 *       defines the default constructor.
 *
 ******************************************************************************************
 ** Delegating constructor
 ******************************************************************************************
 * Note: A delegating constructor uses another constructor from its own class to perform 
 *       its initialization. It is said to “delegate” some (or all) of its work to this 
 *       other constructor
 * 
 * Note: The default constructor is used automatically whenever an object is default 
 *       or value initialized, Default initialization happens
 *
 *       >  When we define nonstatic variables (§ 2.2.1, p. 43) or 
 *          arrays (§3.5.1, p.114) at block scope without initializers
 *
 *       >  When a class that itself has members of class type uses the 
 *          synthesized default constructor
 *
 *       >  When members of class type are not explicitly initialized 
 *          in a constructor initializer list
 *        
 *       >  During array initialization when we provide fewer initializers 
 *			than the size of the When we define a local static object without 
 *			an initializer
 *
 *		 >	When we explicitly request value initialization by writing an 
 *			expressions of the form T() where T is the name of a type (The 
 *			vector constructor that takes a single argument to specify the 
 * 			vector’s size (§ 3.3.1, p. 98) uses an argument of this kind to 
 *			value initialize its element initializer.) 
*/

/*
 ******************************************************************************************
 ** Implicit class-type conversion
 ******************************************************************************************
 *
 * Converting Constructor: Every constructor that can be called with a single argument
 *                         defines an imlicit conversion to a class type from Type of 
 *                         argument
 *
 * Note: A constructor that can be called with a single argument defines an implicit 
 *       conversion from the constructor’s parameter type to the class type.
 *
 *       we noted that the compiler will automatically apply only one class-type conversion
 *      
 *      // error: requires two user-defined conversions:
 *      //    (1) convert "9-999-99999-9" to string
 *      //    (2) convert that (temporary) string to Sales_data
 *      item.combine("9-999-99999-9");
 *
 * Suppressing Implicit Conversions Defined by Constructors
 * We can prevent the use of a constructor in a context that requires an 
 * implicit conversion by declaring the constructor as explicit:
 *
 * example:
 *  class Sales_data {
    public:
        Sales_data() = default;
        Sales_data(const std::string &s, unsigned n, double p):
                   bookNo(s), units_sold(n), revenue(p*n) { }
        explicit Sales_data(const std::string &s): bookNo(s) { }
        explicit Sales_data(std::istream&);
        // remaining members as before
    };
 *
 * Now constructors cann't be used to implicitly create an object
 * item.combine("9-999-99999-9");   // will throw compile error
 * 
 * The explicit keyword is meaningful only on constructors that 
 * can be called with a single argument
 *
 * When a constructor is declared explicit, it can be used only with the 
 * direct form of initialization (§ 3.2.1, p. 84). Moroever, the compiler will not
 * use this constructor in an automatic conversion.
 *
 *
 ******************************************************************************************
 ** Aggregate Classes
 ******************************************************************************************
 * Aggregate classes are typical c style structs with 
 *  - all members public
 *  - no constructor
 *  - no in class initializers
 *  - no base class or virtual function (c++ class related function
 *
 *  Advantage: you can init aggregate classes  using braced list of member initializer
 *
 *  ex:
 *      struct data{
 *          int i;
 *          string s;
 *      }
 *
 *      // valid init
 *      data val1 = {10, "hello"};
 *      data val2 = {"hello", 12}; // error
 *      member should be in sequence of declaration
 *      if list-initializer has fewer element than rest element are
 *      value initialized
 *      if list-initializer has more elements compilation error
 *      include
 *
 */

#include <iostream>
#include <string>

class foo
{
    public:
    foo(std::string s = ""):_s(s){}
    void print() {std::cout << _s << std::endl;}
    std::string _s;
};

void imp_func(foo obj)
{
    obj.print();
}

int main()
{
    // foo obj();   // error declare obj as function obj()
    //              // common/rookie mistake instead of calling
    //              // default constructor
    // obj.print();
    std::string s = "hello_world";
    // implicit conversion of s in to 
    // object of type foo
    imp_func(s);
    return 0;
}
 
