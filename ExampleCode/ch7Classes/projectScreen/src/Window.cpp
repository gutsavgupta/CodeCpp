#include <Window.hpp>

namespace windowMgr{

window::window()
{
    _screen = {screen(80, 24, ' ')};
}

void window::clear(screenIdx idx)
{
    try
    {
        auto Screen         = _screen.at(idx);
        Screen._contents    = std::string((Screen._height*Screen._width), ' '); 
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

}// namespace windowMgr

