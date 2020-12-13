#include <iostream>
#include <string>

class boo {
   public:
    char varboo4;
    boo* operator->() { return this; }
};

class foo {
   public:
    long va1, var2;
    char var3;
    boo var4;

    boo& operator->() { return var4; }
};

class woo {
   public:
    woo(const char* a){};
};

bool operator==(const woo& lhs, const woo& rhs) { return true; }

// foo& operator->(foo& ptr) {}
// error as operator-> must be non-static function
// It has additional, atypical constraints: It must return an object (or
// reference to an object) that also has a pointer dereference operator, or it
// must return a pointer that can be used to select what the pointer dereference
// operator arrow is pointing at

int main() {
    foo obj;
    // auto val = (&obj)->varboo4; // invalid as member pointer will try to get
    // member from pointer type
    auto val = obj->varboo4;  // works because, operator -> will keep finding
                              // the meber until it returns the class object
                              // which has overloaded operator->
    bool check = (woo("hello") == "yellow");

    int a;
    double b;
    std::cin >> a >> b;
    std::cout << a << ", " << b << std::endl;
    return 0;
}
