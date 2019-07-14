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
 * NOTE: Functions defined in the class are implicitly inline
 * 
 * NOTE: Member functions access the object on which they were 
 *       called through an extra, implicit parameter named this.
 * 
 * NOTE: Objects that are const, and references or pointers to 
 *       const objects, may call only const member functions.
 *
 * NOTE: the compiler processes classes in two steps—the member 
 *       declarations are compiled first, after which the member 
 *       function bodies, if any, are processed. Thus, member 
 *       function bodies may use other members of their class 
 *       regardless of where in the class those members appear.
 *
 * NOTE: The IO classes are types that cannot be copied
 *
 * ###################################################################################
 * ## Constructor
 * ###################################################################################
 *
 * Default Constructor:
 *       Classes control default initialization by defining a 
 *       special constructor, known as the default constructor. 
 *       The default constructor is one that takes no arguments.
 *
 * Synthesized Default Constructor:
 *       The compiler-generated constructor is known as the 
 *       synthesized default constructor, this synthesized 
 *       constructor initializes each data member of the class as follows:
 *          > If there is an in-class initializer (§ 2.6.1, p. 73), 
 *            use it to initialize the member.
 *          > Otherwise, default-initialize (§ 2.2.1, p. 43) the member.
 *
 * Note: Classes control object initialization by defining one or 
 *       more special member functions known as constructors. The 
 *       job of a constructor is to initialize the data members of 
 *       a class object. A constructor is run whenever an object of 
 *       a class type is created
 *
 * Note: When we create a const object of a class type, the object 
 *       does not assume its “constness” until after the constructor 
 *       completes the object’s initialization. Thus, constructors 
 *       can write to const objects during their construction.
 *
 * Note: The compiler generates a default constructor automatically 
 *       only if a class declares no constructors.
 *
 * Note: Under the new standard, if we want the default behavior, we 
 *       can ask the compiler to generate the constructor for us by 
 *       writing = default after the parameter list. The = default can 
 *       appear with the declaration inside the class body or on the 
 *       definition outside the class body. Like any other function, 
 *       if the = default appears inside the class body, the default 
 *       constructor will be inlined; if it appears on the definition 
 *       outside the class, the member will not be inlined by default
 *
 * Note: parameters in constructors are initialized in order in which
 *       they are declared inside the class
 *
 * Note: Even though the constructor initializer list is empty, the 
 *       members of this object are still initialized before the 
 *       constructor body is executed. In the same order of inclusion
 */


#include <iostream>a

class myClass
{
    public:
        void set(const std::string &str) {s1=str;}
        void set(const char* str) { s1 = std::string(str); }
        const std::string& get_c_ref() const { return s1; }
        std::string& get() {return s1; }
    private:
        std::string s1;
};


void test1()
{
    const myClass A;
    myClass B;

    B.set("I am B");
    A.get();
}

int main(int argc, const char* argv[])
{
    return 0;
}
