#include <iostream>
#include <memory>

class BaseClass {
   protected:
    char ProBaseMember{'b'};

   public:
    char PubBaseMember{'b'};

    virtual void foo() { std::cout << "BaseClass foo called" << std::endl; }
};

class DerivedClass : public BaseClass {
   protected:
    char ProDerMember;

   public:
    char PubDerMember{'c'};

    void foo() override { std::cout << "DerivedClass foo called" << std::endl; }
};

class FinalClass final : protected BaseClass {
   protected:
    char ProFinMember;

   public:
    char PubFinMember{'d'};

    void foo() override { std::cout << "FinalClass foo called" << std::endl; }
};

// Error can't derive final class
// class Error : FinalClass {};

int main() {
    std::unique_ptr<BaseClass> ptrBase =
        std::make_unique<BaseClass>(BaseClass());
    ptrBase->foo();

    // error as final inherit base as protected
    // ptrBase = std::make_unique<BaseClass>(FinalClass());

    // okay to do implicit conversion betweeen Derived and BaseClass;
    ptrBase = std::make_unique<BaseClass>(DerivedClass());
    ptrBase->foo();  // foo of base is called because we passed an object of
                     // derived class which gets copied in make_unique and hence
                     // loosing it's dynamic type

    // not okay error
    // ptrBase = std::make_unique<DerivedClass>(DerivedClass());

    // for private inheritance below will throw error
    BaseClass baseObj = DerivedClass();
    baseObj.foo();  // foo of base will be called because while copying object
                    // of derived class as base class, dynamic type is lost

    // valid to typecase derived ptr to base ptr
    // if derive inherit it's base as public:
    ptrBase.reset(new DerivedClass());
    ptrBase->foo();  // foo of derived class, because the pointer type is passed

    // Note: Dynamic type can only retain for pointer and reference type
    auto& DynamicBase = *ptrBase;
    DynamicBase.foo();

    // legal, however not safe until we know that Dynamic base will have
    // DerivedClass obj
    DerivedClass& derRef1 = static_cast<DerivedClass&>(DynamicBase);
    std::cout << "derRef1.PubDerMember:" << derRef1.PubDerMember << std::endl;

    // legal, however unsafe and not defined
    DerivedClass& derRef2 = static_cast<DerivedClass&>(baseObj);
    std::cout << "derRef2.PubDerMember:" << derRef2.PubDerMember << std::endl;

    // Dynamic cast is much safe
    try {
        auto& derRef3 = dynamic_cast<DerivedClass&>(DynamicBase);
    } catch (...) {
        std::cout << "exception thrown for derRef3" << std::endl;
    }
    try {
        auto& derRef4 = dynamic_cast<DerivedClass&>(baseObj);
    } catch (...) {
        std::cout << "exception thrown for derRef3" << std::endl;
    }
}
