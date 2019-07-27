/*
 * To support different kinds of IO processing, the 
 * library defines a collection of IO types
 *
 * ########################################################################
 * ## Header            |   Type
 * ########################################################################
 * iostream             |   istream, wistream reads from a stream
 *                      |   ostream, wostream writes to a stream
 *                      |   iostream, wiostream reads & writes a stream
 *                      |
 * fstream              |   ifstream, wifstream (reads files)
 *                      |   ofstream, wofstream (writes files)
 *                      |   fstream, wfstream (reads & writes file)
 *                      |
 * sstream              |   istringstream, wistringstream (read str)
 *                      |   ostringstream, wostringstream (---)
 *                      |   stringstream, wstringstream (obvious)
 * ########################################################################
 *
 * wcin, wcout, wcerr are wide-char (wchar_t) type supported IO buffer
 *
 * Note:
 *          The types ifstream and istringstream inherit from istream
 *          The Types ofstream and ostringstream inherit from ostream
 *
 * Note:
 *  Everything that we cover in the remainder of this section applies equally to 
 *  plain streams, file streams, and string streams and to the char or wide-character 
 *  stream versions.
 *
 * 1. No Copy or Assign for IO Objects
 * 2. Condition States
 *      a)  strm::iostate
 *      b)  strm::badbit    = 0x01
 *      c)  strm::failbit   = 0x04
 *      d)  strm::eofbit    = 0x02
 *      e)  strm::goodbit   = 0x00
 *
 *      f)  s.eof()
 *      g)  s.bad()
 *      h)  s.fail()
 *      i)  s.good()
 *      j)  s.clear()           // reset all condtion values in stream s to valid state
 *      k)  s.clear(flags)      // reset the condition to flags (type: strm::iostate)
 *      l)  s.setstate(flags)   // Adds specified condition
 *      m)  s.rdstate()         // returns current condition as strm::iostate
 *
 * Note:    while(cin) --> while(!cin.fail())
 *
 *      iosate: 0(eof), 0(fail), 0(bad)
 *
 * cout << "hi!" << endl;   // writes hi and a newline, then flushes the buffer
 * cout << "hi!" << flush;  // writes hi, then flushes the buffer; adds no data
 * cout << "hi!" << ends;   // writes hi and a null, then flushes the buffer
 *      
 * ########################################################################
 * Tying Input and Output Streams Together
 *
 *  -   any attempt to read the input stream will first flush the buffer 
 *      associated with the output stream
 *
 *  -   One version takes no argument and returns a pointer to the output 
 *      stream, if any, to which this object is currently tied. The function 
 *      returns the null pointer if the stream is not tied
 *
 *  -   The second version of tie takes a pointer to an ostream and ties 
 *      itself to that ostream. That is, x.tie(&o) ties the stream x to the 
 *      output stream o
 *
 *  -   We can tie either an istream or an ostream object to another ostream
 *
 * ########################################################################
 * File Input and Output
 *
 * fstream fstrm;           // Create an unBound file stream
 * fstream fstrm(s);        // Create a fstream with file s open
 *
 * fstream fstrm(s, mode)   // Create a fstream with file s open with mode 
 * fstrm.open(s)            // open s
 * fstrm.open(s, mode)      // open s with mode
 * 
 * fstrm.close()            // close file
 * fstrm.is_open()          // return bool indicating file associated with 
 *                          // fstream
 *
 * Note:
 *  calling open on a file stream that is already open will fail and set failbit. 
 *  Subsequent attempts to use that file stream will fail
 *
 *  When an fstream object goes out of scope, the file it is bound to is 
 *  automatically closed
 *
 *  The only way to preserve the existing data in a file opened by an ofstream
 *  is to specify app or in mode explicitly
 *
 *  Any time open is called, the file mode is set, either explicitly or implicitly.
 *  Whenever a mode is not specified, the default value is used.
 * 
 * ########################################################################
 * String Stream
 *  
 * sstream strm;            // Unbound stringstream
 * sstream strm(s);         // Hold copy of string s, explicit constructor
 *
 * strm.str();              // return a copy of string hold by strm
 * strm.str(s);             // copies string s into strm; return void
 *
 * @@ istringstream
 *
 * Note:
 *  An istringstream is often used when we have some work to do on an entire line,
 *  and other work to do with individual words within a line.
 *
 * @@ ostringstream
 *
 * Note:
 *  An ostringstream is useful when we need to build up our output a little 
 *  at a time but do not want to print the output until later
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>

namespace IOLibrary
{

std::istream& ProcessInput(std::istream& input)
{
    std::string i1;
    long i2; float i3; char i4;
    
    std::cout << "goodBit: " << input.goodbit << " :: "
              << "eofBit: "  << input.eofbit << " :: "
              << "failbit: " << input.failbit << " :: "
              << "badbit: "  << input.badbit << std::endl;

    // reads a line with following format
    // string long float char
    while (!input.fail())
    {
        input >> i1 >> i2 >> i3 >> i4;

        std::cout   << i1 << " :: "
                    << i2 << " :: "
                    << i3 << " :: "
                    << i4 << std::endl;

        std::cout   << "good: " << input.good() << " :: "
                    << "fail: " << input.fail() << " :: "
                    << "bad: "  << input.bad()  << " :: "
                    << "eof: "  << input.eof()  << " :: "
                    << "iostate: " << input.rdstate() << std::endl;

    }
    
    /** clear the input **/
    input.clear();
    return input;
}



}

int main()
{
    std::ifstream fileStrm("input.txt");
    IOLibrary::ProcessInput(fileStrm);
    return 0;
}
