/** Note: 
 * 
 * 
*/
#include <iostream>

namespace tEXAMPLE5
{
    void test1()
    {
        int mArr[10][20][30] = {0};
        const decltype((mArr))    dArr1 = mArr;         // int dArr1[10][20][30]
        const decltype(*mArr)     dArr2 = mArr[0];      // int (&dArr2)[20][30]
        const decltype(**mArr)    dArr3 = mArr[0][0];   // int (&dArr3)[30]
        const decltype(&(**mArr)) dArr4 = &(mArr[0][0]);

        auto &nArr = mArr;
        auto nArr1 = mArr;      // nArr1 = &(mArr[0])
        auto nArr2 = mArr[0];   // nArr2 = &(mArr[0][0])     
    }   

    void test2()
    {
        int ia[3][4]{
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        for(auto p = ia; p != ia+3; p++)
        {
            for(auto q = *p; q != *p + 4; q++)
            {
                std::cout << *q << std::endl;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    tEXAMPLE5::test2();
    return 0;
}
