/*
 * *****************************************************************************************
 * ** static Class members
 * *****************************************************************************************
 *
 * Static Memeber of a class is assosiated with the class and not with the objects of class
 *  
 *  -> Like any other member, static members can be public or private.
 *  
 *  -> The static members of a class exist outside any object. Objects 
 *     do not contain data associated with static data members
 *  
 *  -> Similarly, static member functions are not bound to any object; 
 *     they do not have a this pointer. As a result, static member 
 *     functions may not be declared as const, and we may not refer to 
 *     this in the body of a static member. This restriction applies 
 *     both to explicit uses of this and to implicit uses of this by calling 
 *     a nonstatic member
 *
 *  -> Ways of accessing static member
 *      
 *      // through scope resolution
 *      CLASS_TYPE::static_member
 *      
 *      // though member(.) operator
 *      CLASS_OBJECT.static_member
 *      
 *      // though (->) operator
 *      CLASS_OBJPTR->static_member
 *
 *      Note operator"" _l is literal operator
 *           like 10u where u is literal to convert it to 
 *           unisigned
 *
 *           int operator"" _g(int weight) // converts it to gram
 *           int operator"" _k(int weight) // converts it to kgs
 *
 * NOTE: As with any other member function, we can define a static member function 
 *       inside or outside of the class body. When we define a static member 
 *       outside the class, we do not repeat the static keyword. The keyword appears 
 *       only with the declaration inside the class body
 *
 * NOTE: in general, we may not initialize a static data member inside the class. 
 *       Instead, we must define and initialize each static data member outside 
 *       the class body.
 *
 * In-Class Initialization of static Data Members
 *
 *  Note: we can provide in-class initializers for static members that have 
 *          const integral type 
 *          constexprs of literal type
 *
 *  Note: If the member is used only in contexts where the compiler can substitute the 
 *        member’s value, then an initialized const or constexpr static need not be 
 *        separately defined. However, if we use the member in a context in which the 
 *        value cannot be substituted, then there must be a definition for that member
 *
 *  Note: A static data member can have incomplete type (§ 7.3.3, p. 278). In particular, 
 *        a static data member can have the same type as the class type of which it is a 
 *        member.
 *      
 *       Another difference between static and ordinary members is that we can use a 
 *       static member as a default argument
 *
 */

#include <iostream>

// @literal class type
class DemoStr
{       
        const char* p;
        size_t s;
    public:
        template<size_t N>
        constexpr DemoStr(const char (&a)[N])
        : p(a), s(N) {}
        constexpr char getChar(size_t n) const
        {
            return p[n];
        }

        constexpr size_t getLower(size_t i=0, size_t c=0) const
        {
            return i == getCount() ? c :
                    getChar(i) >= 'a' && getChar(i) <= 'z' ? getLower( i+1, c+1):
                                                             getLower( i+1, c);
        }

        constexpr size_t getCount() const { return s; }
};

template<long long N>
void func()
{
    std::cout << N << std::endl;
}

template<long long N>
constexpr long long fibonaci()
{
    return N <= 1 ? N : ( fibonaci<N-2>()+fibonaci<N-1>() ) ;
}

template<>
constexpr long long fibonaci<1>()
{
    return 1;
}

template<>
constexpr long long fibonaci<0>()
{
    return 0;
}

int main(const int argc, const char *agrv[])
{
    std::cout << "Hello world has lower char: ";
    func<DemoStr("Hello world").getLower()>();

    std::cout << "fibonaci of " << 10 <<" : ";
    func<fibonaci<50>()>();
    return 0;
}
