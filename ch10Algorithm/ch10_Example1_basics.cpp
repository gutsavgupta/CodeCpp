/* NOTE: The generic algorithms do not themselves execute container operations. They
 *       operate solely in terms of iterators and iterator operations. The fact that the
 *       algorithms operate in terms of iterators and not container operations has a
 *       perhaps surprising but essential implication: Algorithms never change the size
 *       of the underlying container. Algorithms may change the values of the
 *       elements stored in the container, and they may move elements around within
 *       the container. They do not, however, ever add or remove elements directly.
 *
 * NOTE: Algorithms that take a single iterator denoting a second sequence assume
 *       that the second sequence is at least as large at the first.
 *
 * NOTE: Algorithms that write to a destination iterator assume the destination is large
 *       enough to hold the number of elements being written.
 *
 * ##################################################################################
 * ## insert iterator
 * ##################################################################################
 * One way to ensure that an algorithm has enough elements to hold the output is to
 * use an insert iterator. An insert iterator is an iterator that adds elements to a
 * container
 *
 * Ordinarily, when we assign to a container element through an iterator, we
 * assign to the element that iterator denotes. When we assign through an insert iterator,
 * a new element equal to the right-hand value is added to the container
 *
 * IMP: we will use back_inserter, which is a function defined in the iterator header
 *      back_inserter takes a reference to a container and returns an insert iterator
 *      bound to that container
 *
 *      #include <iterator>
 *      #include <vector>
 *
 *      void example()
 *      {
 *          vector<int> vec;
 *          auto it = back_inserter(vec);
 *          *it = 42; // vec now has one element with value 42
 *      }
 *
 * We frequently use back_inserter to create an iterator to use as the 
 * destination of an algorithm. For example:
 *          vector<int> vec; // empty vector
 *          // ok: back_inserter creates an 
 *          // insert iterator that adds elements to vec
 *          fill_n(back_inserter(vec), 10, 0);  // appends ten elements to vec
 *
 * #################################################################################
 * ## Predicates
 * #################################################################################
 * A predicate is an expression that can be called and that returns a value that 
 * can be used as a condition.
 *
 *
 * #################################################################################
 * ## Lambda Expression
 * #################################################################################
 *
 * Callable notion: 
 * We can pass any kind of callable object to an algorithm. An object or expression 
 * is callable if we can apply the call operator (§ 1.5.2, p. 23) to it. That is, 
 * if e is a callable expression, we can write e(args) where args is a comma-separated 
 * list of zero or more argumentsWe can pass any kind of callable object to an algorithm.
 * An object or expression is callable if we can apply the call operator to it. That is,
 * if e is a callable expression, we can write e(args) where args is a comma-separated
 * list of zero or more arguments
 *
 * There are two other kinds of callables: classes that overload the function-call
 * operator, which we’ll cover in § 14.8 (p. 571), and lambda expressions
 *
 * form of lamda expression
 * [capture list] (parameter list) -> return type  {function body}
 *
 * where capture list is an (often empty) list of local variables defined in the enclosing
 * function; return type , parameter list, and function body are the same as in any
 * ordinary function. However, unlike ordinary functions, a lambda must use a trailing
 * return (§ 6.3.3, p. 229) to specify its return type
 *
 * We can omit either or both of the parameter list and return type but must always
 * include the capture list and function body:
 *          auto f = [] { return 42; };
 *
 * We call a lambda the same way we call a function by using the call operator
 *          cout << f() << endl;
 *
 * Omitting the parentheses and the parameter list in a lambda is equivalent to
 * specifying an empty parameter list. Hence, when we call f, the argument list is
 * empty. If we omit the return type, the lambda has an inferred return type that
 * depends on the code in the function body
 *
 * Unlike ordinary functions, a lambda may not have default arguments Therefore,
 * a call to a lambda always has as many arguments as the lambda has parameters.
 * Once the parameters are initialized, the function body executes
 *
 * ## isShorter lambda
 * [](const string& a, const string& b) -> bool
 * { return a.size() < b.size(); }
 *
 * The empty capture list indicates that this lambda will not use any local
 * variables from the surrounding function
 *
 * A lambda may use a variable local to its surrounding function only if the
 * lambda captures that variable in its capture list
 *
 * A lambda can use names that are defined outside the function in which the
 * lambda appears (withouth mentioning it in capture-list). The capture list
 * is used for local nonstatic variables only; lambdas can use local statics
 * and variables declared outside the function directly.
 *
 * 
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>

namespace algo
{

void test1()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8};

    auto cnt = std::count(vec.begin(), vec.end(), '\3');

    std::cout << cnt << std::endl;
}

template <typename _class>
std::size_t size(_class obj)
{
    return obj.size();
}

template <typename _class, std::size_t _n>
std::size_t size(_class (&arr)[_n])
{
    return _n;
}

void test2()
{
    auto lambda1 = [](int a, int b) -> int{
        return a+b;
    };

    std::cout <<  lambda1(10,20) << std::endl;
}

}

int main(int argc, const char *argv[])
{
    algo::test1();
    algo::test2();

    // Type deduction //
    // Template deduction //
    // case 1
    int arr[100];
    std::cout << algo::size(arr) << std::endl;


    return 0;
}
