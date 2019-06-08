/* Important points about iterators
 * Note: iterator type is dependent on container type
 *       way to indirect access to the elements of container(vector, string)
 *       valid iterators, pointing to element and point to one past last element
 *       Operation supported:
 *      
 *       *iter          Return reference to the elem, denoted by iter
 *       iter->mem      indirect access to member of elem denote by iter
 *                      same as (*iter).mem
 *       ++iter, --iter Increment, Decrement iter to refer to next or prev
 *       iter1 == iter2 Equal if they denote same element 
 * Note: valid iterators should be deferences (i.e that are denoting elem of a container)
 *       deferencing end iterator is also invalid
 * 
 *       Every templated type class has implementation of iterator class in-itself
 *       string::iterator               string::const_iterator
 *       vector<class Obj>::iterator    vector<class Obj>::const_iterator
 *       for geting const_iterator, use cbegin() and cend()
 * 
 * Note: String and Vector iterator supports iterator airthmetic
 *       iter += n
 *       iter + n
 *       itr1 - itr2
 *       <, <=, >=, >     
 * 
 * Note: One cool application of iterators and reading elements
 *       binary search on containers with comparator function
 *       if given time try to implement genric binary search for
 *       and genral class object
*/ 

#include <iostream>
#include <string>
#include <vector>

namespace tEXAMPLE3
{
    template<typename T>
    using vec = std::vector<T>;
    using str = std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    void test1()
    {
        str s1 = "hello world!!";
        auto sItr = static_cast<str::iterator>(&s1[3]);
        for(;sItr != s1.end(); sItr++)
        {
            cout << *sItr;
        }   cout << endl;
    }

    void test2()
    {
        std::vector<int> v{1,2,3,4};
        auto itr1 = v.cbegin();
        auto itr2 = v.cend();
        decltype(itr2-itr1) count = itr2-itr1;
        cout << count << endl;
    }

    void test3()
    {
        long a[] = {1,2,3,4,5};
        auto &ra = a; 
        long (&r2)[5] = a;

    }
}

int main(int argc, char const *argv[])
{
    tEXAMPLE3::test1();
    tEXAMPLE3::test2();
    return 0;
}
