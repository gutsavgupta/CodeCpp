#include <iostream>

class MyClass {
   private:
    long num{0}, den{0};

   public:
    MyClass() = default;
    MyClass(long _num, long _den) : num(_num), den(_den) {}

    MyClass operator+(const MyClass lhs) {
        std::cout << __func__ << "::called memeber" << std::endl;
        MyClass res{*this};
        res.AddFunc(lhs);
        return res;
    }

    void AddFunc(const MyClass rhs) {
        den *= rhs.den;
        num = (num * rhs.den + rhs.num * (den / rhs.den));
    }

    void SubFunc(const MyClass rhs) { AddFunc(MyClass{-rhs.num, rhs.den}); }

    void MulFunc(const MyClass rhs) {
        den *= rhs.den;
        num *= rhs.num;
    }

    void DivFunc(const MyClass rhs) { MulFunc(MyClass{rhs.den, rhs.num}); }

    template <typename StreamType>
    void print(StreamType& ostream) {
        ostream << "(" << num << "/" << den << ") = " << (double)num / den
                << std::endl;
    }

    MyClass& operator+=(const MyClass& rhs) {
        AddFunc(rhs);
        return *this;
    }

    operator std::string() const {
        char buffer[20];
        snprintf(buffer, 20, "%.5lf", (double)num / den);
        return std::string(buffer);
    }
};

// better to define in this form, if we want rhs to be different
// types and we know operator+ is symmetric, i.e lhs and rhs should
// be handled for both the types
MyClass operator+(const MyClass& lhs, const MyClass& rhs) {
    std::cout << __func__ << "::called" << std::endl;
    MyClass res = lhs;
    res.AddFunc(rhs);
    return res;
}

int main() {
    MyClass frac1{1, 2};
    MyClass frac2{2, 3};
    MyClass frac3{1, 3};

    auto res = frac1 + frac2 + frac3;
    res.print(std::cout);

    res = frac1.operator+(frac2);
    res.print(std::cout);

    res = operator+(frac2, frac3);
    res.print(std::cout);

    frac1 += frac1;

    // with current system
    // frac1.AddFunc(frac1);
    // frac1.print(std::cout);

    // frac1.SubFunc({1, 2});
    // frac1.print(std::cout);

    // frac1.DivFunc({125, 1});
    // frac1.print(std::cout);

    std::string a = "hello";

    // valid because std::string define operator+() overload
    // as non-member function, hence lhs can be of different type
    std::string b = a + static_cast<std::string>(frac1);
    std::cout << b << std::endl;

    return 0;
}
