//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0342_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0342_H

#include <cmath>

using namespace std;

class Solution {
    // 若n=4^x，n=2^(2*x)，n是完全平方数且n是2的幂
public:
    bool isPowerOfFour(const int &n) {
        if (n <= 0) {
            return false;
        }
        auto r = (int) sqrt(n);  // 检查完全平方数
        if (r * r != n) {
            return false;
        }
        return (1 << 30) % r == 0; // 检查指数是否为2的幂
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0342_H
