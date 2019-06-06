/* This example is created to understand basics
 * of vector library in c++ and create some ex
 * program to test it out in present code
 * 
 * Note: Vector --> template
 *       Vector<type> --> type   
 *       Templated object can be defined with "instantiation"
 * 
 * Note: ways to initialize vector
 * // Direct Initailization
 * vector<int> i{1,2,3,4};
 * vector<int> i(i2.begin(), i2.end());     // i2 is a vector of same type
 * vector<int> i(i3);                       // i3 is a vector of same type
 * vector<int> i(n);                        // n copy of value initialize obj
 * vector<int> i(n, Tval);                  // n copy of obj with value Tval
 * 
 * // In-Direct Initailization
 * vector<int> i = i4;
 * vector<int> i = {a,b,c...};
 * 
*/

#include <iostream>
#include <vector>


namespace tEXAMPLE2
{
    template<typename T>
    using vector = std::vector<T>;      // using templated typedef
    using std::cin;
    using std::cout;
    using std::endl;

    struct myObj
    {
        myObj()
            {cout << "default contructor" << endl;}
        myObj(const myObj &obj)
            {cout << "Copy Constructor" << endl;}
        // adding explicit to the declaration
        // explicit myObj(int &val)
        // above will invalidate all Initailization of myObj
        // in which implicitly constuctor is being called
        myObj(const int &val)
            {cout << "Param Constructor" << endl;}
        // myObj& operator=(int t)
        // {
        //     cout << "assign operator called" << endl;
        //     return *this;
        // }
    };

    void test1()
    {
        // vector<long> longVector;             // valid declaration
        myObj           s1(10);                 // param Constructor                   
        vector<myObj>   t1;                     // empty vector, no constuctor called
        vector<myObj>   t2(2);                  // two default constuctor called
        vector<myObj>   t3(2, s1);              // two copy constuctor

        vector<myObj>   t4(2, 10);              // interesting; for explicit it fails
        // above implements in following ways
        // myObj temp(10); int count = 2;       // param constuctor
        // while(count--){t4.push_back(temp);}  // copy Constructor
        
        cout << "======== 2nd phase =========" << endl;
        //t1.push_back(s1);                       // copy Constructor
        //t1.push_back(10);                       // para Constr then Copy Constr
        //vector<myObj> t5{s1,2,s1,4};
        myObj temp = static_cast<float>(5);     // for explicit it fails
        temp = static_cast<int>(10.0);          // for explicit it fails
    }

    void test2()
    {
        // Note::           Vector are efficient for dynamic allocation
        //                  More to learn in Containers::Chapter
        //
        // Implications::   Loops can get tricky if it changes tha
        //                  If it changes the size of vector, we must
        //                  ensure the correctness of the Loops
        //
        // Warning::        Also as I tried to explore, the "range-for" loop
        //                  should not change the size of vector or sequence
        //                  over which it is iterating
        //
        using str = std::string;
        std::vector<int> vecInt;
        std::vector<str> vecStr;

        str words;
        int input;
        while(cin>>input){vecInt.push_back(input);}
        while(cin>>words){vecStr.push_back(words);}

        for(str w: vecStr){std::cout << w << ",";}std::cout << std::endl;
        for(int i: vecInt){std::cout << i << ",";}std::cout << std::endl; 
    }
}

int main( int argc, const char *argv[])
{
    /* write the code here */
    tEXAMPLE2::test1();
    tEXAMPLE2::test2();
    return 0;
}     
