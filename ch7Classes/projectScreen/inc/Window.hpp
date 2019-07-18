/*
 * Window manager
 *  author:     utsav gupta
 *  created-on: 15th july 2019
 *
 */

#pragma once

#include <Screen.hpp>
#include <vector>
#include <exception>
#include <iostream>

// forward declaration
namespace screenMgr{
class screen;
}

namespace windowMgr{

class window
{
    public:
        using screen    = screenMgr::screen;
        using screenIdx = std::vector<screen>::size_type;

        // @friend function clear
        void clear(screenIdx idx);
        
        // @constructor
        window();

    private:
        std::vector<screen> _screen;
};

}// namespace windowMgr
