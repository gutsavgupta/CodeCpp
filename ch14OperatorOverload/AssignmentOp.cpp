#include <iostream>

class foo {
   public:
    int a{0};
    foo() = default;
    foo(int i) : a(i) {}
    foo& operator=(const foo& rhs) { a = rhs.a; }
    // foo& operator=(const int i) { a = 10; }
};

int main() {
    // test the implicit assignment
    foo obj;
    obj = 23;
    std::cout << obj.a << std::endl;
    return 0;
}
