/*
 * ch5Example1_simpleStatement.cpp
 *  created on: 22nd June, 2019
 *  autor:      gutsavgupta
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#ifdef __DEBUG__
#define DEBUG(msg) std::cout << __func__ << ":: " \
                             << msg << std::endl 
#else
#define DEBUG(msg) while(0)
#endif

namespace chapter5          {
namespace simpleStatements  {

/*
 * Note:    Testing NULL statements
 *          usually null statements shall be used
 *          at places where language requires statement
 *          but program's logic doesn't
 *
 *          if, swtich, while expect a single statement
 *          after them, though the set of statement grouped
 *          by {} are single statement called compound statement
 *          and had their own scope. Compound statement eclosed
 *          by curly braces{}, does not have ";" after '}'
 *
 * usage:   if (condition)
 *              statement
 *          else (condition)
 *              statement
 *
 *          while (condition)
 *              statement
 *
 * Note:    variable defined in a while/for condition or body
 *          are created and destroyed on each iteration
 *
 */

static inline
std::string getGrades(int marks, std::vector<char> &grades)
{
    std::string gradeLetter = "";
    (marks < 50)?(void)(gradeLetter += grades[0]):
    (marks > 99)?(void)(gradeLetter += "A++"):
    (void)( gradeLetter += grades[(marks-40)/10],
            (marks%10 > 7)?(void)(gradeLetter += '+'):
            (marks%10 < 4)?(void)(gradeLetter += '-'):
            (void)0);
    return gradeLetter;
}

void test1()
{
    std::string word{};
    DEBUG("write \"exit\" to end !!");
    while(std::cin >> word && word != "exit") /*null statement*/;

    auto val = 0, sum = 0;
    while(val <= 10) sum+=val, ++val;
    DEBUG("sum, val: " << sum << ", " << val); 
}

void test2()
{
    int a;
    std::vector<char> grades{'F','E','D','C','B','A'};
    while(std::cin >> a)
    {
        DEBUG("Your Grade:: " << getGrades(a, grades));
    }
}

/*
 * Switch-Case statement
 *
 * switch(expresion){
 *
 * case label:
 * ......
 * case label:
 * .....
 * }
 *
 * IMP: case labels should be "constexpr int"
 *      expression should evaluate/convertible to int
 *
 *      swtich case control flow do-not jum vairable
 *      initialization, whether implicit or explicit
 *      If in case you want to define/initalize the 
 *      object in particular case use blocks
 *      case label:
 *      {
 *          // do initialzations
 *          std::string word = "stuff";
 *      }
 *
 * Tradional "For" Statement
 * for( initializtion; condition; expression)
 *      statement;
 *
 * Range For Statement
 * for (declaration: expression)
 *      statement;
 *
 * Expression: must represent sequence
 *  > initializer list
 *  > array, object of type vector<> , string
 *  > that has begin() and end() members
 *  > that return iterator
 *  > inside Range for loop, container size should not
 *    change as range-for loop caches the start and end 
 *    iteration value.
 *
 * Ex: range-for loop:
 *     for (auto &r = v)
 *     {
 *          r *= 2;
 *     }
 *
 *     traditional for loop
 *     for (auto beg = v.begin(), end = v.end(); beg != end; beg++)
 *     {
 *          auto &r = *beg;
 *          r*=2;
 *     }
 *
 */

void test3()
{
    long stat = 10; 
    auto func = [&stat]() -> int{
        return --stat;
    };
    // illustration of once major point
    // while loop can have condition initalizing
    // loop variable or other
    while (int i = func()) DEBUG("value of i: " << i );

    // on the otherhand, do-while{} loop doesn't have
    // the same condition
    // do
    // {
    //     int v1,v2;
    //     DEBUG("Hello c++!!");
    // }while (v1); // error v1 was not declared in this scope
}

/*
 * four jump statement
 *  > break
 *  > continue
 *  > goto
 *  > return
 *
 * GOTO statement
 * goto and label to which it jumps must be in same function
 * like a switch statement, a goto statement cannot bypass a 
 * initialization of variable to place where variable is getting out of
 * scope, jumping back to previous statements, destroys and recreate the
 * variable
 *
 * Exception handling
 *  >   throw block try to traverse nested catch block up the ladder
 *      until a proper catch handler is found
 *  >   if no appropriate catch handler is found then std::terminate is called
 *      which garuntees to stop the program exec
 *  >   implicit type_casting does not take place in exception handling
 *      thowing char, while catching int won't solve problem.
 *      Although, derived classes are converted into base class
 *      if catch lbock of base class is defined
 */

void test4()
{
    // reset std::cin //
    std::cin.clear();
    std::cin.ignore(100, '\n');
    int a,b;
    DEBUG("Please enter a b");
    while (std::cin >> a >> b)
    {
        try
        {
            if (b == 0)
                throw std::runtime_error("divide by zero !!");
            int quot = a%b;
            DEBUG("result: " << quot);
        }
        catch (std::runtime_error &e)
        {
            DEBUG(e.what());
        }
        catch ( ... )
        {
            DEBUG("default exception handler");
        }
    }
}

} // namespace simpleStatements
} // namespace chapter5a

int main()
{
    /** paste your code below **/
    namespace ch5SS   = chapter5::simpleStatements;

    ch5SS::test1();
    ch5SS::test2();
    ch5SS::test3();
    ch5SS::test4();
    return 0;
}
