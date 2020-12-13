#include <iostream>

#define PRINT(VAL) std::cout << #VAL << "::" << VAL << std::endl

class fooSimple {
   public:
    void func() {}
};

class fooVirtual {
   public:
    virtual void func() {}
};

int main() {
    std::cout << "Hello, world!\n" << std::endl;
    fooSimple fooSimpleObj;
    fooVirtual fooVirtualObj;
    PRINT(sizeof(fooSimpleObj));
    PRINT(sizeof(fooVirtualObj));
    return 0;
}
