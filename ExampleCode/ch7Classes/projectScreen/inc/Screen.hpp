/*
 * Project Screen && window manager
 *  author:     Utsav
 *  created-on: 15th July 2019
 *
 */
#pragma once

#include <Window.hpp>
#include <iostream>
#include <string>

// forward delaration
namespace windowMgr{
class window;
}

namespace screenMgr{

class screen
{
    public:
        //@Type Aliases
        using pos       = std::string::size_type;
        using window    = windowMgr::window;
        
        // @friendship declaration
        friend window;
        
        //@Constructors
        screen()    = default;

        screen(pos width, pos height, pos cursor)
            : _width(width),
              _height(height)
        {
            _cursor = (cursor < _height*_width)?cursor:0;
        }

        screen(pos width, pos height, char c)
            : _width(width),
              _height(height),
              _contents(_height*_width, c){}
        
        // @implicit inline 
        char get() const { ++_access_ctr_get;
                            return _contents[_cursor]; }

        // @explicit inline
        inline char get(pos h, pos w) const;

        // @inlined later
        screen& move(pos r, pos c);

        screen& set(char);
        screen& set(pos, pos, char);
        screen& display(std::ostream& out);
        const screen& display(std::ostream& out) const;
    private:
        pos _cursor = 0;
        pos _height = 0;
        pos _width  = 0;
        std::string _contents;

        // @mutable member
        // to track number of calls
        mutable size_t _access_ctr_get;

        // @helper function
        void _display(std::ostream &out) const;
        
};

}// namespace screenMgr
