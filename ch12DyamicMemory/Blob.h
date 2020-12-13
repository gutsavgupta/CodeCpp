/*
 * Blob Class which stores shared resources
 * the copy of blob class doesn't copy the 
 * actual resources to new created object
 */


#pragma once

#include <iostream>
#include <stdarg.h>
#include <memory>

namespace blob {

// tBlob is templated over the generic class
// although main aim of blob class is to share
// resourses efficiently

template <typename T>
class tBlob
{
    public:
        using value_type = T;

    public:
        // default constructors
        tBlob() = default;

        tBlob(...) : m_objectPtr(...) {}

        // get the pointer refernce
        auto& operator() () { return *m_objectPtr; }
        auto& operator() () const { return *m_objectPtr; }

    protected:
        // create a shared pointer for type T object
        std::shared_ptr<value_type> m_objectPtr;
};

} // namespace blob

