/*
 * Feature for specialization
 *  > Default args
 *  > inline
 *  > constexpr
 *
 * #DEFAULT-ARGUMENT
 * Some functions have parameters that are given a particular value 
 * in most, but not all, calls. In such cases, we can declare that 
 * common value as a default argument for the function. Functions 
 * with default arguments can be called with or without that argument
 *
 * typedef string::size_type sz;  // typedef see § 2.5.1 (p. 67)
 * string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
 *
 * Here we’ve provided a default for each parameter. A default argument is specified as
 * an initializer for a parameter in the parameter list. We may define defaults for one or
 * more parameters. However, if a parameter has a default argument, all the parameters
 * that follow it must also have default arguments.
 * 
 * Part of the work of designing a function with default arguments is ordering the
 * parameters so that those least likely to use a default value appear first and those
 * most likely to use a default appear last.
 *
 * Although it is normal practice to declare a function once inside a header, it is legal to 
 * redeclare a function multiple times. However, each parameter can have its default
 * specified only once in a given scope. Thus, any subsequent declaration can add a
 * default only for a parameter that has not previously had a default specified. As usual,
 * defaults can be specified only if all parameters to the right already have defaults
 *
 * #INLINE-KEYWORD
 * A function specified as inline (usually) is expanded “in line” at each call. 
 * If shorterString were defined as inline, then this call
 * 
 * inline const string & shorterString(const string &s1, const string &s2)
 * {
 *      return s1.size() <= s2.size() ? s1 : s2;
 * }
 *
 * cout << shorterString(s1, s2) << endl;
 * cout << (s1.size() < s2.size() ? s1 : s2) << endl;
 *
 * The inline specification is only a request to the compiler. 
 * The compiler may choose to ignore this request
 *
 * #CONSTEXPR FUNCTION
 * A constexpr function is a function that can be used in a constant expression 
 * (§ 2.4.4,p. 65). A constexpr function is defined like any other function but 
 * must meet certain restrictions: The return type and the type of each parameter 
 * in a must be a literal type (§ 2.4.4, p. 66), and the function body must contain 
 * exactly one return statement:
 *
 * constexpr int new_sz() { return 42; } 
 * constexpr int foo = new_sz();  // ok: foo is a constant expression
 *
 * The compiler will replace a call to a constexpr function with its 
 * resulting value. In order to be able to expand the function immediately, 
 * constexpr functions are implicitly inline.
 *
 * A constexpr function body may contain other statements so long as those 
 * statements generate no actions at run time. For example, a constexpr function may 
 * contain null statements, type aliases (§ 2.5.1, p. 67), and using declarations.
 *
 * A constexpr function is permitted to return a value that is not a constant:
 * A constexpr function is not required to return a constant expression.
 *
 * Unlike other functions, inline and constexpr functions may be defined multiple 
 * times in the program. After all, the compiler needs the definition, not just the 
 * declaration, in order to expand the code. However, all of the definitions of a given
 * inline or constexpr must match exactly. As a result, inline and constexpr
 * functions normally are defined in headers
 *
 * Aids for Debugging
 * This approach uses two preprocessor facilities: assert and NDEBUG
 * The assert Preprocessor Macro
 *
 * assert(expr);
 * evaluates expr and if the expression is false (i.e., zero), then assert writes a
 * message and terminates the program. If the expression is true (i.e., is nonzero), 
 * then assert does nothing.
 *
 * The NDEBUG Preprocessor Variable
 * The behavior of assert depends on the status of a preprocessor variable named
 * NDEBUG. If NDEBUG is defined, assert does nothing. By default, NDEBUG is not
 * defined, so, by default, assert performs a run-time check
 *
 * compiler define below macro by default
 * _ _func_ _ string literal function name
 * _ _FILE_ _ string literal containing the name of the file
 * _ _LINE_ _ integer literal containing the current line number
 * _ _TIME_ _ string literal containing the time the file was compiled
 * _ _DATE_ _ string literal containing the date the file was compiled
 */

int main(const int argc, const char *const argv[])
{
    return 0;
}
