/*
 * There is an overall best match if there is one and only one function for which
 * • The match for each argument is no worse than the match required by any other
 *   viable functionC++ Primer, Fifth Edition
 * • There is at least one argument for which the match is better than the match
 *   provided by any other viable function
 * 
 * If after looking at each argument there is no single function that is preferable, then 
 * the call is in error. The compiler will complain that the call is ambiguous.
 *
 * ex:
 *
 * void func(int, int);
 * void func(double, double);
 *
 * func(1, 2.0);    // error as no best choice is clear
 * 
 * func(2.0, 'a');  // calls func(double, double)
 *
 * func(2, 'a');    // calls func(int , int)
 *
 * # CANDIDATE FUNCTION
 *
 * The first step of function matching identifies the set of overloaded functions
 * considered for the call. The functions in this set are the candidate functions. A
 * candidate function is a function with the same name as the called function and for
 * which a declaration is visible at the point of the call.
 *
 * # VIABLE FUNCTION
 * The second step selects from the set of candidate functions those functions that can
 * be called with the arguments in the given call. The selected functions are the viable
 * functions. To be viable, a function must have the same number of parameters as
 * there are arguments in the call, and the type of each argument must match—or be
 * convertible to—the type of its corresponding parameter
 * 
 * void manip(long);
 * void manip(float);
 * manip(3.14); // error: ambiguous call
 * The literal 3.14 is a double. That type can be converted to either long or float.
 * Because there are two possible arithmetic conversions, the call is ambiguous
 *
 * ## Function POINTER
 * Read it from book
 */


int main()
{
    return 0;
}
