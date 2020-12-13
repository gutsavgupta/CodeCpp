#include <iostream>
#include <string>

class foo {
    long val;

   public:
    explicit foo(long _val) : val(_val) {}

    // conversion
    operator int() const { return static_cast<int>(val); }

    explicit operator long*() { return static_cast<long*>(&val); }

    explicit operator const long&() const { return val; }

    explicit operator bool() const { return val; }
};

struct LD {
    LD(double = 0.0) {}

    operator double() const { return 1.0; }
    operator float() const { return 2.0; }
};

void f1(int i) { std::cout << __func__ << "::int" << std::endl; }
void f1(LD i) { std::cout << __func__ << "::LD" << std::endl; }

int main() {
    foo obj1(23);

    foo obj2(obj1 + 46);

    if (obj1) {  // this conversion to bool can happen if explicit bool() is
                 // defined or implicit conversion to airthmetic type/ptr type
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }

    std::string s1 = static_cast<std::string>("heelo");

    LD obj;
    double d1 = obj;
    float d2 = obj;
    f1(d1);
    return 0;
}

