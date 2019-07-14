/*
 * C++ Access Specifier
 *
 * In C++ we use access specifiers to enforce encapsulation:
 *      
 *      • Members defined after a public specifier are accessible to all parts of the
 *        program. The public members define the interface to the class.
 *      
 *      • Members defined after a private specifier are accessible to the member 
 *        functions of the class but are not accessible to code that uses the class. 
 *        The private sections encapsulate (i.e., hide) the implementation
 *
 * Note:    A class may define members before the first access specifier. 
 *          Access to such members depends on how the class is defined. 
 *          If we use the struct keyword, the members defined before the 
 *          first access specifier are public; if we use class, then the 
 *          members are private. The only difference between struct and 
 *          class is the default access level
 *
 * #################################################################################
 * ## Friend
 * #################################################################################
 * A class can allow another class or function to access its nonpublic members by 
 * making that class or function a friend. A class makes a function its friend by 
 * including a declaration for that function preceded by the keyword friend
 *
 * example:
 *  class foo{
 *      private:
 *          int priv_mem;
 *      public:
 *          //interface member;
 *          friend void foo_friend(args);
 *  };
 *
 *  void foo_friend(args, foo& fooObj)
 *  {
 *      // we can access foo private member //
 *      fooObj.priv_mem;
 *  }
 *
 * Friend declarations may appear only inside a class definition; they may appear 
 * anywhere in the class. Friends are not members of the class and are not affected 
 * by the access control of the section in which they are declared
 *
 * NOTE: Although user code need not change when a class definition changes, the 
 * source files that use a class must be recompiled any time the class changes.
 */

int main()
{
    return 0;
}
