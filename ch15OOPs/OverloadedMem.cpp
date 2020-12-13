#include <functional>
#include <iostream>

#define PRINT_FUNC() \
    (std::cout << __CLASS_NAME << "::" << __func__ << " is called")

class Base {
    static constexpr const char* __CLASS_NAME = "Base";

   public:
    void foo(int, char) { PRINT_FUNC() << " foo(int,char)" << std::endl; }

    std::function < void(int, char) bindedFunction;

   protected:
    void foo(char) { PRINT_FUNC() << " foo(char)" << std::endl; }
};

class Derived : public Base {
    static constexpr const char* __CLASS_NAME = "Derived";

   public:
    // make visible all the version of foo to be public in derived
    using Base::foo;

    void foo(int) { PRINT_FUNC() << " foo(int)" << std::endl; }
};

int main() {
    Derived DObj;
    DObj.foo('a');
}

