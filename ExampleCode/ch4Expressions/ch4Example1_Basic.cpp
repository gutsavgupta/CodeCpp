/* In this tutorial we will try to focus on operator and operands
 * We will go through many general terms in c++ and will try to 
 * explore as much as possible
 * 
 * Expression:: Sentence formed by one or more operands and evaluates
 *              to some value, eg: variable, built-in literals
 *              More complex Expressions are formed when operators are
 *              involved too
 * 
 * Unary operator   :: Operator that act on single operand      :: ex: *(deref), &
 * Binary operator  :: Operator that act on two operands        :: ex: a*b, a+b, ==
 * ternary operator :: Operator that act on three operand       :: ex  (a)?(b):(c)
 * functions        :: Can operate on infinite operads
 * 
 * Overloaded operators::   When we define the operator functioning as per our class type
 *                          we refer to it as Overloaded Operator.
 *                          However: the number of operands, precedence and associativity
 *                          cannot be changed
 * 
 * Expressions are of two type:
 * 1. lvalue        :: expression which can stand on left-hand side of assignment operator
 * 2. rvalue        :: expression which can stand on right-hand side of assignment operator
 * Roughly speaking :: expression which can result in object or // function ??//
 *                  :: also it depends on usage, const obj are not lvalues
 *                  :: some obj used as rvalue aw well, if used as rvalue, we use value of obj
 *                  :: though if obj are used lvalue we use the object identity (its location in memory)
 * 
 * assignment operator  :: takes left operand as lvalue and right operand as rvalue     :: return lvalue
 * address of operator  :: taked lvaue operand                                          :: return rvalue
 * derefence operator   ::                  ???                                         :: return lvalue
 * 
 * ex: cout << i << " " << i++ << endl;
 * in above example order of evaluation is not garunteed // undefined
 * i++ can evaluate first then i, or vice versa
 * 
 * operator that garuntees evaluatio order
 * &&, ||, ?:, ','\comma, 
 * 
 * f() + g()*h() + x()
 * 
 * precendence      --> garuntees that g()*h() is done
 * associativity    --> garuntees that f() is added to g()*h() then added to x()
 * eval. order      --> is not garunteed
 * 
 * Note: arithmetic operators have L associativity
 *       uniary(+,-) > (*,/,%) > (+,-)
 *       data type are promted in arithmetic expression
 *       works on arithmetic operands or pointers
 * 
 * Logical Operator::
 * takes operands of type bool or can be converted in type bool
 * return operands of type bool; arithmetic and pointer with 0 --> false, rest --> true
 * return rvalue, requires rvalue
 * 
 * logical OR and AND --> Short-circuit evaluation
 * operator ! has R associativity
 * rest other logical operator has L associativity
 * 
 * a != c < d
 * same as: a != (c<d)
 * 
 * Compound expressions are better/effcient in term of execution
 * operand is evaluated once as compared to normal assignment (where
 * operands are evaluated twice) 
 * 
 * Note:
 * ++a :: prefix operator has lower precendence
 *        increment the variable and return the lvalue/reference
 *        to the same variable
 * a++ :: postfix operator has higer precedence, increment the 
 *        value, return copy of (rvalue) previous value
 * 
 * Member Access
 * obj.mem  :: (.) operator high precedence
 * ptr->Mem :: ->  arrow operator high precedence
 * (*ptr).mem :: (*) derefence and dot, although derefence has lower precedence
 * (*ptr.mem) :: this means derefence mem obj of ptr class --> *(ptr.mem)
 * arrow operator -> yeilds an lvalue always
 * dot operator (.) yeilds lvalue from lvalue object, otherwise r value
 * 
 * ?: conditonal operator is of low precedence
 * of the order of "=", "*=", "+="..execution
 * should be used mostly with parenthesesi
 * cout << str.size()<60 ? "small" : "large" << endl ; // huge blunder
 * ((cout << str.size()) < 60) ? small : (large << endl);
 * 
 * BITWISE operator promotes small init to larger type first
 * then apply 
 * Recomendation --> better to use unsigned bit with bit operator
 * 
 * THE SIZEOF Operator ::
 * sizeof(type) --> return size of type in bytes, return-type constexpr size_t
 * sizeof(expr) --> return size of type of exprs
 * 
 * sizeof operator is evaluted at compile time and has no 
 * rum time evaluation reqiuirement (this can be validated from the fact that
 * c++ is statically typed language i.e at compile time ,, all variables types
 * are fixed)
 * 
 * Comma operator ','
 * 1. very low precedence, actually lowest
 * 2. gaurentees evaluation order
 * 3. Associativy L
 * expr1 , expr2
 * expr1 is evaluated before expr2 
 * return --> right hand_expression
 *        --> return lvalue if right hand expression is lvalue
 * 
 * ## Implicit Conversion
 * Apart from Airthmetic Implicit conversion
 * Array are also converted to pointer to first element when used in
 * expression, except decltype(), sizeof(), type-id, and when assiging 
 * refrences
 * 
 * auto &a = arr; a will of type (arr)[]
 * 
 * Pointers of non-const type are converted to void* Implicit
 * all pointers can be converted to const void*
 * 0, nullptr can be converted to any pointer type
 * 
 * Classes can specify automatic conversion 
 * ex: while(cin) cin --> gets converted into bool Implicitly
 * ex: string a = "hello", c-style string converted to string_type
 * 
 * ## Explicit conversion
 * cast     ::  for Explicitly converting type in c
 * Warning: ::  although required some time, cast are inherently dangerous
 * 
 *  # Named-cast    ::  cast-name<type>(expression)
 *  1.  static_cast<>
 *  2.  dynamic_cast<>
 *  3.  const_cast<>
 *  4.  reinterpret_cast<>
 *  if the type is reference the result is lvalue, else rvalue
 *  the cast-name determines what kind of conversion shall be performed
 * 
 *  # static_cast<>
 *  any well-defined cast excluding low-level const can be performed using 
 *  static_cast<>, it indicates that the conversion is intentional and well-thought
 *  static_cast<> can cast void* ptr to any ptr
 *  and const void* to any const ptr
 *  static_cast is the first cast you should attempt to use. 
        // It does things like implicit conversions between types (such as int to float, 
        // or pointer to void* or vice versa), and it can also call explicit conversion 
        // functions (or implicit ones)
 * 
 *  # reinterpret_cast<> 
 *  is the most dangerous cast, and should be used very sparingly. 
 *  It turns one type directly into another — such as casting the value from one pointer 
 *  to another, or storing a pointer in an int, or all sorts of other nasty things
 * 
 *  C-Style cast
 *  (T)expression OR
 *  T(expression)
 *  both are same
 * 
 *  C-style cast tries below in order
 *  1. If Static_cast<> is possible
 *  2. If Const_cast<> is possible
 *  3. If dynamic_cast<> is possible
 *  4. reinterpret_cast<> // fails for only some case
 */

#if 0
#include <iostream>
#include <vector>

namespace tEXAMPLE1
{
    using std::cout;
    using std::endl;

    void test0()
    {  
        cout << 5 + 10*11/2 << endl;
        cout << 12/3*4+5*15+24%4/2 << endl;
    }

    void test1()
    {
        std::string str = "hello world !!.";
        char last_c     = *--std::end(str);
        std::cout << last_c << std::endl;
    }

    void test3()
    {
        int a[10] = {0,};
        int *ptr  = a;

        ++*(ptr+1);
        // Note prefix operator returns lvalue i.e
        ++a[0] = 10;    // valid
        // Note suffix operator return copy of obj as rvalue
        // a[0]++ = 10;    // invalid
    }

    void test4()
    {
        using vecStr = std::vector<std::string>;
        vecStr myVector{"heelo world","bromance", ""};
        vecStr::iterator iter = myVector.begin();

        cout << *iter++ << endl;            // print heelo world
        // cout << (*iter)++ << endl;       // invalid   
        // cout << *iter.empty() << endl    // invalid
        // ++*iter;                         // invalid
        iter++->clear();
        cout <<  myVector[1] << endl;    // print false

        std::string str = "word";
        std::string ntr = str + ((str[str.size()-1] == 's')?"":"s");

        cout << (~'q'<<6) << endl;
    }

    void test5()
    {
        std::vector<int> ivec {1,2,3,4,5,6,7,8};
        decltype(ivec.size()) count_t = ivec.size();
        decltype(ivec.size()) ivect_t = static_cast<decltype(ivec.size())>(0);

        for(;ivect_t<ivec.size(); ivect_t++, count_t--)
        {
            //cout << ivec[ivect_t] << " " << ivect_t <<" "<< count_t<< endl;
            ivec[ivect_t] = count_t;
            //cout << ivec[ivect_t] << " " << ivect_t <<" "<< count_t<< endl;
        }

        constexpr int size = 5;
        int a[size] = {1,2,3,4,5};
        for(int *p = a, i =0; i < size && p != a+size; ++i, p++)
        {
            cout << *p << " ";
        }cout << endl;

        int x = 1; int y = 1;
 
        (true)? ++x, ++y: --x;//, --y;
        cout << x << " " << y ;

        auto a1 = 'a', b1= 'b';
        auto i = a1+b1;
    }
    
    // static_cast<>
    void test6()
    {
        char a1 = 10, b = 12 , c1 = 13;           // Implicit conversion //
        char *p1 = &a1, *p2 = &b, *p3 = &c1;      // pointer
        int *ip1  = (int*)p1;                   // allowed
        // int *ip2  = static_cast<int*>(p1);   // not allowed as static_cast
                                                // static_cast can convert non-const void* to any pointer
                                                // static_cast can convert const void * to const any pointer
        void *v1 = p1;
        const void *v2 = p2;
        double *dp1 = static_cast<double*>(v1);
        // double d    = static_cast<double>(a);
        // float  *fp1 = static_cast<double*>(v1); invalid
        const double *dp2 = static_cast<const double*>(v1);

        // More examples of static cast
        // static_cast is the first cast you should attempt to use. 
        // It does things like implicit conversions between types (such as int to float, 
        // or pointer to void*), and it can also call explicit conversion functions (or implicit ones)
        // between int <-> long <-> short <-> long long <-> float <-> int <-> double 
        int a;
        double d        = static_cast<double>(a);
        uint16_t u16    = static_cast<uint16_t>(a);
        int ia          = static_cast<int>(d);
        long double ld  = static_cast<long double>(u16);
        long long   ll  = static_cast<long long>(ld);
        unsigned long ul= static_cast<unsigned long>(d);

        // among char type
        char16_t c16;
        char c = static_cast<char>(c);
        wchar_t wc = static_cast<wchar_t>(c);
        float f = static_cast<float>(a);
    }

    void test6b()
    {
        // testing static cast with pointer variation
        int         ia;
        long        la;
        double      da;
        uint16_t    sa;
        unsigned int        uia;
        unsigned long long  ulla;

        // Static_cast does not allow invalid type conversion of pointers
        // int *ptr1_int           = static_cast<int*>(&da);    // not allowed
        // int *ptr2_int           = static_cast<int*>(&la);    // not allowed
        void * ptr3_void        = static_cast<void *>(&uia);
        double* ptr4_doub       = static_cast<double*>(ptr3_void);
    }

    // const_cast<>
    void test7()
    {
        const char ca = 'a';
        const long la = 10;
        // char *tcPtr      = &ca;                      // Invalid as const char * cannot be type castes to char *
        char *ncPtr      = const_cast<char*>(&ca);      // We can use const_cast to exploit the low-level cosnt 
        long *nlPtr      = const_cast<long*>(&la);
        // char newC        = const_cast<char>ca;       // invalid
        // only pointer, reference or pointer to memebers are only allowed;
        // Const_cast can remove the low-level const from the const pointer
        // althoug it cannot change the type of the conversion, just type modifiers
    }

    void test8()
    {
        double d = 3.5, *dPtr = &d;
        int i1 = 2, i2 = 2, *iPtr = &i1;
        int i3 = static_cast<int>(*dPtr);

        cout << (i1*=d) << endl;
        cout << (i2*=static_cast<int>(d)) << endl;

        const std::string *ps;
        void *pv;

        pv = const_cast<void *>(static_cast<const void*>(ps));
    }
}

int main(int argc, char const *argv[])
{
    tEXAMPLE1::test0();
    tEXAMPLE1::test8();
    return 0;
}

#endif
