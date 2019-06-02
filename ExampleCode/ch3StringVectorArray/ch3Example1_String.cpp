/* Example2: string library 
 * part(1)::Notes::Most common string operation
 * 1. os << s       // write s into ostream os              ::  return &ostream
 * 2. in >> s       // write content from istream in to s   ::  return &istream 
 * 3. getline(in,s) // reads a line from in, write in to s  ::  return &istream
 * 4. s.empty()     // return true is s in empty i.e no char::  return bool
 * 5. s.size()      // return length or #of chars in s      ::  return size_t
 * 6. s[i]          // return ref to char at position i     ::  return &char
 * 7. s1 + s2       // return string that conc s1 & s2      ::  return string
 * 8. s1 = s2       // copy s2 to s1                        ::  return &string
 * 9. s1 == s2      // compare s1 to s2 (lexiographically)  ::  return bool
 * 10. s1 != s2     // un-equality check                    ::  return bool
 * 11. <,<=,>=,>    // comparison checks, dictonary ord     ::  return bool
 * 
 * part(2)::Note::String literal, char literal can be converted to string type
 * when the expression requires it, though the string literal and string are
 * of different type
 * 
 * string s1 = "hello" + s2;        // valid and one operand is string
 * string s2 = "hello" + "worlds"   // invalid as two literal don't support add
 * string s3 = s1 + "and" + "s4"    // valid associativity left to right
 * string s4 = "s1" + "and:" + s4   // invalid
 * 
 * part(3)::library to perform vaious operation on char
 * #include <cctpe>
 * contains function likes, isupper(c), islower(c), isgraph(c), isspace(c) etc..
 * 
 * part(4)::For logical "&&" operator, the if any condition becomes false in sequence
 *          the next condition is not evaluated, for example:
 *          while( i < vector.size() && vector[i] == stuff )
 *          {.....other stuff....}
 *          in this scenario if i overflows vector.size(), then vector[i]
 *          won't get evaluated.
 * 
 * part(5)::In range loop, the range will not change even if container size changes  
*/

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

namespace tEXAMPLE1
{
    // typedefs
    using tStrSize = std::string::size_type;
    using tVecSize = std::vector<int>::size_type;

    void test1()
    {
        // test s.size() && s.length()
        std::string s{"whats up buddy"};
        decltype(s.size()) Ssize;
        decltype(s.length()) Slen;
        std::cout << "s.size(): " << (Ssize = s.size()) << std::endl;
        std::cout << "s.length(): " << (Slen = s.length()) <<std::endl;
    }

    // void test2()
    // {
    //     // read until EOF
    //     // std::string words;
    //     // while(std::cin >> words){ std::cout << words << ","; }
    // }

    void test3()
    {
        // test range for syntax style
        // test cctype function in std::namespace
        std::string str1, str2;
        getline(getline(std::cin, str1), str2);
        for(auto itr: str1){
            std::cout << (char)std::toupper(itr);   // print UPPER case letters
            itr = (char)std::toupper(itr);          // tries to change str1, won't work
        }   std::cout << std::endl;

        for(auto &itr: str2){
            std::cout << (char)std::tolower(itr);   // print lower case letters
            itr = (char)std::tolower(itr);          // tries to change str2, works
        }   std::cout << std::endl;
        
        std::cout << "str1: " << str1 << std::endl;
        std::cout << "str2: " << str2 << std::endl;
    }

    void test4()
    {
        std::string hello("This World is bad!!");
        for(auto &c: hello){ 
            c = 'I';
        }   std::cout << hello << std::endl;

        // random test
        // for(char a=0; a < hello.size(); a++){hello[a] = 'x';}
        // std::cout << hello << std::endl;
    }
}

int main(int argc, const char *argv[])
{
    // insert code below //
    tEXAMPLE1::test1();
    tEXAMPLE1::test3();
    tEXAMPLE1::test4();
    return 0;
}