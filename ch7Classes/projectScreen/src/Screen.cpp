#include <Screen.hpp>

namespace screenMgr{

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

screen& screen::move(pos r, pos c)
{
    if ( r <= _height && c <= _width )
    {
        pos row = r*_width;
        _cursor = row + c;
    }
    return *this;
}

screen& screen::set(char c)
{
    _contents[_cursor] = c;
    return *this;
}

screen& screen::set(pos r, pos c, char a)
{
    if( r <= _height && c <= _width)
    {
        pos idx         = r*_height + c;
        _contents[idx]  = a;
    }
    return *this;
}

screen& screen::display(std::ostream& out)
{
    _display(out);
    return *this;
}

const screen& screen::display(std::ostream& out) const
{
    _display(out);
    return *this;
}

void screen::_display(std::ostream& out) const
{
    out << _contents;
}

double screen::rate = 2.4;
std::vector<double> screen::vec(vecSize);

}// namespace screenMgr

