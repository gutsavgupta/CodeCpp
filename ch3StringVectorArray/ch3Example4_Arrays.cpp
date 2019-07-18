/* This Example is to explore various new/complex 
 * Topics related to arrays like, references and 
 * pointer to array struct 
 * 
 * Note: subscript operator used "[]" with library type
 *       forces the opertaor value to be unsigned
 * 
 *       where as this is not the case with built-in 
 *       subscript optiom, used with pointers
 *       int *prt{..};
 *       we can use following ptr[-2], ptr[23];
 *       such kind of values not possible with library subscript
 *       operator
*/
#include <iostream>

namespace tEXAMPLE4
{
    #define myBeg(arr) (arr)
    #define myEnd(arr) ((&arr)+1)

    // resolving scopes
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;

    void test1()
    {
        string arr1[10];
        string arr2[20];
        // populating array of string //
        for(auto &str:arr1){ str = string{"hello world!!"}; }

        // creating a refernce to above array //
        string (&arrRef)[10] = arr1;

        // printing address of array //
        // arrRef+1 --> increment unit is sizeof(arrRef);
        cout << "size of arr[0]: "  << sizeof(arrRef[0])    << endl;
        cout << "Addr of arr[0]: "  << arrRef+0 /*&arr[0]*/ << endl;
        cout << "Addr of arr[1]: "  << arrRef+1 /*&arr[1]*/ << endl;

        cout << "size of arr[0]: "  << sizeof(arrRef)       << endl;
        cout << "Addr of arr: "     << &arrRef+0            << endl;
        cout << "Added +1 to arr: " << &arrRef+1            << endl;

        // create a pointer to above array          //
        // auto deduce it from value substitution   //
        // decltype deduce it from declaration      //
        auto *arrPtr2 = arr2;               // makes arrPtr1 as (string *), pointer to an string
        decltype(&arr2) arrPtr3;            // makes arrPtr2 ad string (*arrPtr2)[20], pointer to an array
        string (*arrPtr)[20] = nullptr;
        arrPtr = &arr2;
        
        for(auto &elem: *arrPtr){ elem = "not fine!!"; }
        cout << "size of arr[0]: "  << sizeof(arrPtr)   << endl; 
        // sizeof(arrPtr)   --> size of pointer in c++ ie 8byte
        // sizeof(*arrPtr)  --> size of string (*)[20]
        cout << "Addr of arr[0]: "  << *arrPtr+0        << endl;
        cout << "Addr of arr[1]: "  << *arrPtr+1        << endl;
 
    }

    struct myclass: string
    {
        using string::string;
        myclass(){cout << "default constructor called" << endl;}
        myclass(const string& rhs): string(rhs){ cout << "pram constructor called" << endl;}
    };

    void test2()
    {
        string rhs{"grat"};
        myclass arr1[2];
        myclass arr2[2]{"hello",""};
        myclass arr3[2]{rhs,rhs};
        myclass *arrPtr = arr3;
        for(auto elem: *arrPtr)
        {
            cout << elem << "," << endl;
        }
        int *(*arrPtr1)[10];        // pointer to array of-> int* [10]
        int *const(*arrPtr2)[10];   // pointer to array of size[10] of const pointer to int
        int *const(*const(*arrPtr3)[10])[10];
        // arrPtr3 is pointer --> array of size[10] of const pointer --> array of size[10] of const pointer --> int
        typedef int* const ArrLvl1[10];         // array of size[10] of const pointer pointing to int
        typedef const ArrLvl1 * ArrLvl2[10];     // array of size[10] of const pointer pointer to array of size[10] of const pointer pointing to int
        //ArrLvl2 *arrPtr4;
        //arrPtr4 = arrPtr3;

        // tricky declarations
        auto arrPtrx = arrPtr1;     // arrPtrx --> int *(*arrPtrx)[10]
        auto arrPtry = *arrPtr1;    // arrPtry --> int **;
        auto arrPtrz = **arrPtr1;   // arrPtrz --> int *
        auto arrPtrw = &arrPtr1;    // arrPtrw --< int *(**arrPtrw)[10]

        // tricket declaration
        decltype(arrPtr1) arrPtrd1;
        // decltype(*arrPtr1) arrPtrd2; // derefrencing in decltype gives you reference type
        decltype(&arrPtr1) arrPtrd3;
        
    }

    // pointers are useful in iterating through an array of object
    // implement my_begin(array) and my_end(array)
    void test3()
    {

        int myArr[10];
        int* arrBeg = myBeg(myArr);
        int* arrEnd = (int*)myEnd(myArr);

        cout << "arrBeg && myArr: " << arrBeg << ", " << &myArr << endl;
        cout << "arrEnd && myArr: " << arrEnd << ", " << &myArr+1 << endl;

        for(; arrBeg!=arrEnd; arrBeg++)
        {
            cout << *arrBeg << endl;
        }

    }

    void test4()
    {
        int myArr[20];

        int * bg = std::begin(myArr);
        int * en = std::end(myArr);
        decltype(en-bg) sz = en-bg;
        // std::ptrdiff_t sz = en+bg; pointer addition not supported
        // en = en + 10;   // supported although not saf;
        // if(en > bg)     // Supported comparision
        // else

        int *p2 = (int*)nullptr+100, *p1 = (int*)0x0100;
        p2 += p1-p2;
        cout << p2 << endl;
    }
}

int main(int argc, char const *argv[])
{
    //tEXAMPLE4::test1();
    //tEXAMPLE4::test2();
    //tEXAMPLE4::test3();
    tEXAMPLE4::test4();
    return 0;
}
