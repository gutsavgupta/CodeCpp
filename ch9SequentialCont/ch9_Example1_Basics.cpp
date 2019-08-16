/*
 * #########################################################################
 * ## Sequential Container Type
 * #########################################################################
 *
 * vector   Flexible-size array, Fast Random Access, Inserting, Deleting
 *          elements other than middle not efficient
 *
 * deque    Double-ended queue. Supports fast random access.
 *          fast insertion and deletion at front or back
 *
 * list     Doubly linked list. Supoprts only bi-direction sequential access
 *          fast-insertion and deletion at any point on the list
 *
 * forward_list Singly link-List. Support sequential access only at one direction
 *          fast-insertion and deletion at any point in the list
 *
 * array    Fixed-size array. Support fast random access
 *          Cannot add or remove elemets
 *
 * string   A specialized container, similar to vector, for character
 * 
 * NOTE:    To create a container as a copy of another container, the container and element 
 *          types must match. When we pass iterators, there is no requirement that the container
 *          types be identical. Moreover, the element types in the new and original containers can
 *          differ as long as it is possible to convert (§ 4.11, p. 159) the elements we’re copying
 *          to the element type of the container we are initializing
 *
 *          When we initialize a container as a copy of another container, the container
 *          type and element type of both containers must be identical
 *
 * NOTE:    Unlike built-in arrays, the library array type does allow assignment. 
 *          The left-and right-hand operands must have the same type
 *
 *          array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};
 *          array<int, 10> a2 = {0}; // elements all have value 0
 *          a1 = a2;  // replaces elements in a1
 *          a2 = {0}; // error: cannot assign to an array from a braced list
 *
 * NOTE:    The sequential containers (except array) also define a member named
 *          assign that lets us assign from a different but compatible type, or 
 *          assign from a subsequence of a container. The assign operation replaces 
 *          all the elements in the left-hand container with (copies of) the elements 
 *          specified by its arguments
 *
 * ########################################################################
 * ## SWAP
 * ########################################################################
 * The swap operation exchanges the contents of two containers of the same type. 
 * After the call to swap, the elements in the two containers are interchanged
 *
 * With the exception of arrays, swapping two containers is guaranteed to be 
 * fast—the elements themselves are not swapped; internal data structures are swapped
 *
 * NOTE:    Excepting array, swap does not copy, delete, or insert any elements and is
 *          guaranteed to run in constant time
 *
 *          The fact that elements are not moved means that, with the exception of string,
 *          iterators, references, and pointers into the containers are not invalidated
 *      
 *          They refer to the same elements as they did before the swap. However, after 
 *          the swap, those elements are in a different container
 *
 * NOTE:    The emplace functions construct elements in the container. The arguments to 
 *          these functions must match a constructor for the element type
 *
 * #########################################################################
 * ## Accessing Elements (sequential container)
 * #########################################################################
 * back()   -> return a reference to the last element in c. Undefined if c is empty
 * front()  -> return a reference to the first element in c.
 * c[]      -> return an indexed reference. undefined if n>=c
 * c.at(n)  -> return an reference to the element at nth index,
 *             if empty throw, out_of_range exception
 *
 * #########################################################################
 * ## Growth of the vector
 * #########################################################################
 * This allocation strategy is dramatically more efficient than reallocating the container
 * each time an element is added. In fact, its performance is good enough that in
 * practice a vector usually grows more efficiently than a list or a deque, even
 * asthough the vector has to move all of its elements each time it reallocates memory.
 *
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <array>
#include <list>



namespace container
{
    template<typename iterator_t>
    void printContainer(iterator_t begin, iterator_t end)
    {
        while(begin != end) 
        {
            std::cout << *begin++ << ", ";
        }   std::cout << std::endl;
    }

    void TEST_list()
    {
        std::list<int> myList{0,2,3,4};

        // traverse in list //
        // itr -> list<int>::iterator
        std::cout << "######## simple traversing (iterator) ########" << std::endl; 
        for(auto itr = myList.begin(); itr != myList.end(); ++itr)
        {
            std::cout << *itr << " ";
        }   std::cout << std::endl;

        std::cout << "######## simple traversing (range) ########" << std::endl;
        for(auto &elem : myList)
        {
            std::cout << elem << " ";
        }   std::cout << std::endl;
        
        // reset the lis //
        myList.clear();

        // insert 5000 random number //
        for(int i=0; i<5000; ++i)
        {
            myList.push_back(rand());
        }
        
        #if 0
        int oddCnt = 0;
        // Modifying on the go //
        for(auto itr = myList.begin(); itr != myList.end(); ++itr)
        {
            if (*itr&0x01) // odd
            {
                ++oddCnt;
                myList.push_back(rand());
            }
        }   
        std::cout << "Odd Elem Count: " << oddCnt << std::endl;
        std::cout << "List size: " << myList.size() << std::endl;
        #endif

        #if 1
        int oddCnt = 0;
        // Modyfying on the go //
        for(auto itr = myList.begin(); itr != myList.end(); )
        {
            if (*itr&0x01) // odd
            {
                ++oddCnt;
                *itr = rand();
                continue;
            }
            ++itr;
        }
        std::cout << "Odd Elem Count: " << oddCnt << std::endl;
        std::cout << "List size: " << myList.size() << std::endl;
        #endif
        

    }

    void TEST_array()
    {
        std::array<std::string, 20> myArr;
        
    }

    
    template <typename iterator>
    void print(iterator begin, iterator end)
    {
        for(auto itr = begin; itr != end; itr++)
        {
            std::cout << *itr << ", ";
        }   std::cout << std::endl;
    }

    void TEST_vector()
    {
        std::list<int> list1    = {1,2,3,4};
        std::vector<int> vec1   = {5,6,7,8};

        std::vector<double> vec2(std::begin(vec1),std::end(vec1));
        print(vec2.begin(), vec2.end());

        std::vector<double> vec3(std::begin(list1), std::end(list1));
        print(vec3.begin(), vec3.end());
    }

    void test_iterator()
    {
        std::list<int> list1 = {1,2,3,4,5};

        for (auto iter = list1.begin(); iter != list1.end(); )
        {
            if (*iter%2)    // odd
            {
                iter = list1.insert(iter, *iter);
                // iter += 2;  // error probably
                iter++;
                iter++;
            }
            else
            {
                iter = list1.erase(iter);

            }
        }

        print(list1.begin(), list1.end());
    }

}


int main()
{
    // seeding random //
    srand (time(NULL));

    container::TEST_list();
    container::TEST_vector();
    container::test_iterator();
    return 0;
}
