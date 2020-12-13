#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int TestFun(int, int) {
    std::cout << __func__ << ":: called for TestFun" << std::endl;
    return 0;
}

int BinFun(int, int) {
    std::cout << __func__ << ":: called for BinFun" << std::endl;
    return 0;
}

class BinObj {
   public:
    int operator()(int, int) {
        std::cout << __func__ << ":: called for BinObj" << std::endl;
        return 0;
    }
};

template <typename T>
class tempConst {
   public:
    std::function<T> funObj;

    template <typename ObjType>
    tempConst(const ObjType& obj) {
        funObj = obj;
    }
};

int main() {
    // creating a lamda for the same
    auto BinLam = [](int, int) -> int {
        std::cout << __func__ << ":: called for BinLam" << std::endl;
        return 0;
    };

    // creating std::bind
    auto BinFunBnd =
        std::bind(BinFun, std::placeholders::_2, std::placeholders::_1);

    auto BinTestFunBnd =
        std::bind(TestFun, std::placeholders::_2, std::placeholders::_1);

    auto BinObjBnd =
        std::bind(BinObj(), std::placeholders::_1, std::placeholders::_2);

    // std::Bind(obj, placeholder_x1, placeholder_x2..) is like type
    // std::Bind<T> , where T
    // T = decltype(obj) (placeholder_x1, ...)
    decltype(BinFunBnd) tmp(BinTestFunBnd);

    std::vector<std::function<int(int, int)>> funcVec{
        BinLam, BinFunBnd, BinObjBnd, BinFun, BinObj()};

    std::for_each(
        funcVec.begin(), funcVec.end(),
        [](typename decltype(funcVec)::value_type& callObj) { callObj(0, 0); });

    tempConst<int(int, int)> tempObj(BinObjBnd);

    return 0;
}
