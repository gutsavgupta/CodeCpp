/*
 * #################################################################
 * ## Structure of generic Algorithm
 * #################################################################
 * 
 * Note: The most fundamental property of any algorithm is the list of
 *       operations it requires from its iterator(s)
 *       Such as find, require only the ability to access an element
 *       through the iterator, to increment the iterator, and to
 *       compare two iterators for equality
 *
 * The iterator operations required by the algorithms are grouped
 * into five iterator categories listed below
 * 
 * Each algorithm specifies what kind of iterator must be supplied
 * for each of its iterator parameters
 *
 * Input Iterator       : Read, but not write, single-pass, increment only
 * Output Iterator      : Write, but not read; single-pass, increment only
 * Forward Iterator     : Read and write; multi-pass, increment only
 * Bidirectional        : Read and write; multi-pass, incr. & decrm.
 * Random-access        : Read and write; multi-pass, full iterator airthmetic
 *
 *
 *
 */

#include <iostream>
#include <string>

int main()
{
    std::string hello = "HELLO";
    std::string mello = "what not";

    const auto& ref = (hello.size()<5) ? hello : mello;

    std::cout << ref << std::endl;
    return 0;
}
