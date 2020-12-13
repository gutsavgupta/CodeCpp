#include <iostream>
#include <memory>
#include <vector>

class Base {
   protected:
    char preBaseVar{'B'};

   public:
    virtual void func() {
        std::cout << "Base::" << __func__ << " called" << std::endl;
    }

    Base() = default;

    // copy constructor
    // Base(const Base& rhs) : preBaseVar(rhs.preBaseVar) {}
    Base(const Base& rhs) = delete;

    // copy operator
    Base& operator=(const Base& rhs) {
        preBaseVar = rhs.preBaseVar;
        return *this;
    }

    Base& operator=(Base&& rhs) {
        preBaseVar = rhs.preBaseVar;
        return *this;
    }
};

class Derived : public Base {
   protected:
    char proDerivedVar{'D'};

   public:
    void func() override {
        std::cout << "Derived::" << __func__ << " called" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    baseObj = Base();
    std::vector<char> spaceVec[10];
    // baseObj = derivedObj; error as copy assignement is not defined

    // Doesn't allocate memory
    // only calls constructor
    auto ptr1 = new (&spaceVec) std::vector<char>[10]();

    // only allocates memory doesn'y call constructor
    auto ptr2 = (std::vector<char>*)::operator new(sizeof(std::vector<char>));

    // allocate memory and calls constructor
    auto ptr3 = new std::vector<char>();
}
