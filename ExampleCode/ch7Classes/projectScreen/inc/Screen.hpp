/*
 * Project Screen && window manager
 *  author:     Utsav
 *  created-on: 15th July 2019
 *
 */
#pragma once

#include <iostream>
#include <string>

namespace screen{

class screen
{
    public:
        //@Type Aliases
        using pos = std::string::size_t;

        //@Constructors
        screen()    = default;

        screen(pos width, pos height, pos cursor)
            : _width(width),
              _height(height),
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

// @member definition
char screen::get(pos h, pos w) const
{
    ++_access_ctr_get;
    if ( h <= _height && w <= _width )
    {
        pos row = h*_width;
        pos idx = row + w;
        return _contents[idx];
    }
    return '\0';
}

inline 
screen& screen::move(pos r, pos c)
{
    if ( r <= _height && c <= _width )
    {
        pos row = r*_width;
        _cursor = row + c;
    }
    return *this;
}

inline
screen& screen::set(char c)
{
    _contents[_cursor] = c;
    return *this;
}

inline
screen& screen::set(pos r, pos c, char a)
{
    if( r <= _height && c <= _width)
    {
        pos idx         = r*_height + c;
        _contents[idx]  = a;
    }
    return this*
}

inline
screen& screen::display(std::ostream& out)
{
    _display(out);
    return *this;
}

inline
const screen& screen::display(std::ostream& out) const
{
    _display(out);
    return *this;
}

inline
void screen::_display(std::ostream& out) const
{
    out << _contents;
}
}// namespace screen
