/*
 * Description: This is my wrapper over std::exception class
 *              we can add more wrappers over here to throw more details
 *
 * funciionality: we can add exception message dynamically
 *                for any exception variable
 */

#ifndef _MYEXCEPTION_
#define _MYEXCEPTION_

#include <exception>
#include <cstring>

namespace sale
{

class exception : public std::exception
{
public:
    using BASE = std::exception;
    
    // @overrideen function //
    exception(const char* msg): m_msg(msg){}

    // @overridden function //
    virtual const char* what() const throw() {return m_msg;}

private:
    const char *m_msg;
};


} // namespace sale
#endif
