/*
 * Description: Person Class
 * Feature
 *  > Store Name and Age of person (v_1.0.0)
 *
 */

#pragma once

#include <iostream>
#include <string>

namespace person{

class Person
{
    public:
        //@constructor
        Person():
            _addr{"INVALID"},
            _name{"INVALID"} 
        {
        }

        //@object calls
        const std::string& getName() const;
        const std::string& getAddr() const;
        
        //@static calls
        static std::istream& read(Person& obj,
                                  std::istream& inp);
        static std::ostream& dump(const Person& obj,
                                  std::ostream& out);
    private:
        std::string _addr;
        std::string _name;
};

inline
const std::string& Person::getName() const
{
    return _name;
}

inline
const std::string& Person::getAddr() const
{
    return _addr;
}

inline
std::istream& Person::read(Person& obj, std::istream& inp)
{
    return inp >> obj._name >> obj._addr;
}

inline
std::ostream& Person::dump(const Person& obj, std::ostream& out)
{
    return out << "Person name:\t" << obj._name
               << "Person addr:\t" << obj._addr
               << std::endl;
}

}// namespace Person
