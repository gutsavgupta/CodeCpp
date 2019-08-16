/*
 * Insert iterators: These iterators are bound to a container and can be used to
 * insert elements into the container.
 * 
 * Stream iterators: These iterators are bound to input or output streams and
 * can be used to iterate through the associated IO stream.
 * 
 * Reverse iterators: These iterators move backward, rather than forward. The
 * library containers, other than forward_list, have reverse iterators.
 * 
 * Move iterators: These special-purpose iterators move rather than copy their
 * elements
 *
 * ############################################################################
 * ## Insert Iterator
 * ############################################################################
 * There are three kinds of inserters. Each differs from the others as to where elements
 * are inserted:
 *  • back_inserter (§ 10.2.2, p. 382) creates an iterator that uses push_back.
 *  • front_inserter creates an iterator that uses push_front.
 *  • inserter creates an iterator that uses insert. This function takes a second
 *
 * argument, which must be an iterator into the given container. Elements are
 * inserted ahead of the element denoted by the given iterator.
 * 
 * Note: We can use front_inserter only if the container has push_front.
 *       Similarly, we can use back_inserter only if it has push_back.
 *
 *
 * ############################################################################
 * ## Stream Iterator
 * ############################################################################
 * 
 * ----------------------------------------------------------------------------
 * input stream iterator
 * ----------------------------------------------------------------------------
 *
 * standards and operation
 *
 * istream_iterator<T> in(s)        : in reads value of type 'T' from input stream 's'
 * istream_iterator<T> end          : Off-the end iterator for an istream_iterator that reads
 *                                    value of type T
 * in1 == in2                       : returns true if in1 and in2 must read same type 'T'
 *                                    and are off-the end iterator or are containing same 
 *                                    stream
 * in1 != in2                       : opposite of the equal to operator
 *
 * *in                              : return reference to the value read from stream
 * in->mem                          : similar to (*in).mem
 *
 * ++in, in++                       : Reads the next value from the input stream using the
 *                                    >> operator for the element type. As usual, the prefix
 *                                    version returns a reference to the incremented iterator.
 *                                    The postfix version returns the old value
 *
 * ---------------------------------------------------------------------------
 * Outstream iterator
 * ---------------------------------------------------------------------------
 *
 * ostream_iterator<T> out(os)      : out writes values of type T to output stream os.
 * ostream_iterator<T> out(os, d)   : out writes values of type T followed by d to output stream
 *                                    os. d points to a null-terminates character array.
 *
 * out = val                        : writes val to the ostream to which out is bound using the 
 *                                    << operator val must have a type that is compatible with the
 *                                    type that out can write
 *
 * *out, ++out, out++               : These operation exist but do nothing to out. Each operator
 *                                    returns out
 *
 */


#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>

template<typename T>
T& func_inp(std::istream& _stream, T& _container)
{
    std::istream_iterator<int> input_iter(_stream);
    std::istream_iterator<int> input_ieof;

    auto _cont_iter = std::back_inserter(_container);
    
    std::copy(input_iter, input_ieof, _cont_iter);
    return _container;
}

template<typename T>
void func_out(std::ostream& _stream, T& _container)
{
    std::ostream_iterator<int> output_iter(_stream, ", ");
    
    std::copy(std::begin(_container),
              std::end(_container),
              output_iter);
}

void run1()
{
    // Input from cin
    std::vector<int> _my_vec;

    func_out(std::cout,
             func_inp(std::cin, _my_vec));
}

void run2()
{
    // Input from file
    std::string _file_name;

    std::cout << "Enter file name: ";
    std::cin >> _file_name;

    std::ifstream _file(_file_name);
    std::vector<int> _my_vec;
    
    if (not _file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    func_out(std::cout,
             func_inp(_file, _my_vec));
}

int main()
{
    run2();
    return 0;
}

