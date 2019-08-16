/*
 * More information on lambda expression
 * in previous example: ch10Example1_basics.cpp
 *
 * #####################################################################
 * ## Lambda Captures & Returns
 * #####################################################################
 * 
 * [] --> No capture
 *
 * [names] --> capture names by value
 *
 * [&] --> capture all local non-static variable by ref
 *
 * [=] --> capture all local non-static variable by val
 *
 * [&, identifier_list] --> capture all local ns by ref, except identifier
 *                          _list, capture them by val
 *
 * [=, reference_list]  --> capture all local ns by val, except identifier
 *                          _list, capture them by ref (must be preceded
 *                          with '&')
 *
 * lambda classes
 * When we define a lambda, the compiler generates a new (unnamed) class type that
 * corresponds to that lambda. When we pass a lambda to a function, we are defining
 * both a new type and an object of that type: The argument is an unnamed object
 * of this compiler-generated class type. Similarly, when we use auto to define a
 * variable initialized by a lambda, we are defining an object of the type
 * generated from that lambda
 *
 * By default, the class generated from a lambda contains a data member
 * corresponding to the variables captured by the lambda. Like the data members of any
 * class, the data members of a lambda are initialized when a lambda object is created
 *
 * #####################################################################
 * ## Bind Function
 * #####################################################################
 * The bind function can be thought of as a general-purpose function adaptor.
 * It takes a callable object and generates a new callable that “adapts” the
 * parameter list of the original object. The general form of a call to bind is:
 *              auto newCallable = bind(callable, arg_list);
 *
 *
 */
