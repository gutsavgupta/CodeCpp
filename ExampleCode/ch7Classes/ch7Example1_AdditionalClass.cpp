/*
 * #####################################################################################
 * ## Additional class feature
 * #####################################################################################
 *  > Type members
 *  > in-class initiallizer for members of class type
 *  > mutable data members
 *  > inline member function
 *  > returning *this from a member function
 *  > more on friendship
 *
 * Note: unlike ordinary members, members that define types must appear 
 *       before they are used. As a result, type members usually appear 
 *       at the beginning of the class
 *
 * Note: For the same reasons that we define inline functions in headers 
 *       (§ 6.5.2,p. 240), inline member functions should be defined in 
 *       the same header as the corresponding class definition.
 *
 * #####################################################################################
 * ## mutable Data Members
 * #####################################################################################
 * It sometimes (but not very often) happens that a class has a data member that we want 
 * to be able to modify, even inside a const member function. We indicate such members by 
 * including the mutable keyword in their declaration. A mutable data member is never 
 * const, even when it is a member of a const object. Accordingly, a const member function 
 * may change a mutable member
 *
 * Note: functions returning reference to class obj are usually helpfull in cascading various
 *       functions in one line, for example
 *
 *       Obj.set_param().display_param();
 *
 *       // here set_param must be reference returning func
 *
 *       Obj_class& set_param()
 *       {
 *          ...****...
 *          return *this
 *       }
 *
 * Note: A const member function that returns *this as a reference should have a return 
 *       type that is a reference to const
 *
 * Note: We can overload a member function based on whether it is const for the same
 *       reasons that we can overload a function based on whether a pointer parameter 
 *       points to const
 *
 *       ex:
 *          void get() const;   // can be called for both, but for non-const obj, later one
 *                              // is preferred over const one
 *          void get();         // can only be called for non-const object
 *
 * #####################################################################################
 * ## Class declaration
 * #####################################################################################
 * Class Declarations
 * Just as we can declare a function apart from its definition (§ 6.1.2, p. 206), 
 * we can also declare a class without defining it:
 *
 *  class screen;   // declaration of the screen class
 *                  // This declaration, sometimes referred to as a forward declaration
 *
 * >    After a declaration and before a definition is seen, the type Screen is an incomplete 
 *      type—it’s known that Screen is a class type but not known what members that type contains. 
 * 
 * >    We can use an incomplete type in only limited ways: We can define pointers or references 
 *      to such types, and we can declare (but not define) functions that use an incomplete type 
 *      as a parameter or return type.
 * 
 * Note: data members can be specified to be of a class type only if the class has been defined. 
 * The type must be complete because the compiler needs to know how much storage the data member 
 * requires.
 */

int main(int argc, char* argv[])
{
    return 0;
}
