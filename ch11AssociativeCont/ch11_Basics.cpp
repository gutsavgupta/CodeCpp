#include <iostream>
#include <vector>
#include <string>

namespace associative_cont {
namespace basics {

class Compare_class
{
    public:
        // default the constructor
        Compare_class() = default;
        
        // param constructor
        Compare_class(std::string &&name, std::string &&game)
            : _name(name), _game(game)
        {
        }

        // define call operator for comparing two complex data of this class
        // make it a satic operator() function
        static bool operator() (Compare_class&& lhs, Compare_class&& rhs);

        // Accessors func.
        const auto& get_name() const {return _name;}
        const auto& get_game() const {return _game;}

        // Modifiers func.
        auto set_name(std::string&& name) { _name = name; }
        auto set_game(std::string&& game) { _game = game; }

    protected:
        // Data members
        std::string _name;
        std::string _game;
};

bool Compare_class::operator() (Compare_class&& lhs, Compare_class&& rhs)
{
    return (lhs.get_name() + lhs.get_game() < rhs.get_name() + rhs.get_game());
}

} // namespace basics
} // associative_cont

int main(const int argc, const char* argv[])
{
    return 0;
}
