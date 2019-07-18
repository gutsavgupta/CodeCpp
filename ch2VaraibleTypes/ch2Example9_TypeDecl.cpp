/* This Example is to illustrate the ways and
 * shortcut defined in c++ to deal with type declaration
 * and to get short type declaration easily
 * 
 * Note:
 * OLD standards way of simplify the type name
 * --typedef--
 * typedef double wages         // wages is typename of double
 * typedef wages base, *pBase   // base is typename for double,
 *                              // pBase is typename for double *
 * 
 * declaration that include typedef defines type-alias
 * rather than definiing the variable, compounf type declaration
 * are also allowed while declaring type-alias
 * 
 * New Standard c++11
 * --Using--
 * using is a way of declaring a alias and assining it a type
 * 
 * using <alias-name> = <alias-type>
 * ex:
 * using wages = double         // wages is of type double
 * 
 * --Auto--
 * auto is the method of deducing the type by the help
 * of compiler, auto variable must have intializer so that compiler
 * can deduce the type of variable by processing the expression
 * if the expression has some type conversion because of the operations involved
 * the variable wil have final type of the result of expression
 * 
 * long int a;
 * long double d;
 * auto c = d+a; // type of c will be long double //
 * 
 * --decltype--
 * 
 * when you want type of some function or variable but don;t want to assing
 * the value of function or variable we can use decltype
 * 
 * ex:
 *      auto ai = 10, &ci = ai;
 *      decltype(ai) x = 100;
 *      decltype(ci) y = ai;
 * 
*/


#if 0
namespace tEXAMPLE9{

    // ---Typedef usage -- //
    typedef double wages;
    typedef double* wagesPtr;
    typedef const double wagesC;

    void test1(){

        wages w1 = 12.45;           // w is of type double
        const wages wc = w1;        // wc is const double
        const wagesPtr wPtr = &w1;  // wPtr is const pointer to double
        wagesC *wcPtr;              // wcPtr is pointer to const double
        wages *const *wpcPtr;       // wpcPtr is pointer to const pointer to double
        const wagesPtr *wpPtr;      // wpPtr is pointer to const pointer to double
    }

    void test2(){

        auto vi = 10;           // vi is of Type int
        auto pi = &vi;          // pi is of Type int*

        // auto vi1 = 10, pi1 = &vi1;       // invalid as auto becomes int because of vi1 = 10;
                                            // and pi1 will be treated as int then
        auto vi1 = 10, *pi1 = &vi1;
        
        // Top -Level const are ignored in auto deduction //
        int nvi = 11;
        const int ci = 10;
        auto ai = vi, aci = ci;     // both ai and aci is of type int
        auto npi = &vi;              // pi is of type int*
        auto cpi = &ci;             // ci is of type const int*
        auto cppi = &(cpi);         // cppi is pointer to pointer to const int [const int **]

        // To enable top-level const, write explicit const //
        const auto cai = vi;
        const auto cbi = 10;
        const auto &cci = vi;
        // auto &cdi = 10;          // Invalid decleartion
        const auto &cei = 10;       // normal rules applies
        auto &cfi = ci;             // const int &cfi
    }

    void test3(){

        const auto ai = 100, &ri = ai;
        decltype(ai) x = 23.0;              // x is a const int
        decltype(ri) j = x;                 // j is a const int &

        // TOP-level const are handled differently with decltype syntax
        // decltype() gives whole type including type modifier
        // for ex: for decltype(ri) will give type (const int &)

        int zi = 10, *pi = &zi;
        decltype(pi) dpi;                   // dpi is int *
        decltype(*pi) dri = zi;             // dri is int &

        int fi = 10;
        double di;
        decltype(fi) m;                     // m is int
        decltype((fi)) mr = m;              // mr is int&
        decltype(di = zi) nai = di;         // nai is double &
                                            // assignment operator return referecne type 
                                            // reference type is of type of left-hand operand
    }

    void test4(){

        const int ci = 10, *pci = &ci;

        auto ai = *pci;                 // ai is of type int
        decltype(*pci) bi = (*pci);     // bi is of type const int&

        int z = 10, y = 11;
        auto di = (z = y);              // di is of type int              
        decltype(z=y) ei = z;           // ei is of type int&
        
    }
}

int main(int argc, const char *argv[]){

    tEXAMPLE9::test1();
    tEXAMPLE9::test2();
    return 0;
}
#endif