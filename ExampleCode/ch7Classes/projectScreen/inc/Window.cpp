/*
 * Window manager
 *  author:     utsav gupta
 *  created-on: 15th july 2019
 *
 */

#pragma once

#include <Screen.hpp>
#include <vector>


namespace window{

class window
{
    public:
        using screen = screen::screen;

    private:
        std::vector<screen> _screen{screen(24,80,' ')};
};

}// namespace window
