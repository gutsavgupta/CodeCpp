#include <iostream>

#define PRINT_FUNC() \
    (std::cout << __CLASS_NAME << "::" << __func__ << " is called")

class Base {
    static constexpr const char* __CLASS_NAME = "Base";

   public:
    using BASE_T = Base;
    using THIS_T = Base;

    virtual long foo(int c = 'a', long l = 10) const& noexcept {
        PRINT_FUNC() << " c:" << c << " l:" << l << std::endl;
        return 0;
    }

   protected:
    virtual long boo(int) { return 10; }
};

class Derived : public Base {
    static constexpr const char* __CLASS_NAME = "Derived";

   public:
    using THIS_T = Derived;

    long foo(int c = 'd', long l = 20) const& noexcept override {
        PRINT_FUNC() << " c:" << c << " l:" << l << std::endl;
        return 1;
    }

    void func() {
        Base* ptr = static_cast<Base*>(this);
        // cannot access protected member from base obj;
        // ptr->boo(10);
        this->Base::boo(10);
    }
};

void print(Base& obj) { obj.foo(); }

void printBaseFoo(Base& obj) { obj.THIS_T::foo(); }

int main() {
    Base baseObj;

    // cannot define an object of abtract class
    Derived derivedObj;
    print(derivedObj);
    print(baseObj);

    std::cout << '\n' << "SCOPE specific foo" << std::endl;
    printBaseFoo(derivedObj);
    printBaseFoo(baseObj);

    derivedObj.BASE_T::foo();
    return 0;
}

