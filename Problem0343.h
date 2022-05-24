//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0343_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0343_H

#include <cmath>

using namespace std;

class Solution {
    // 尽可能分成3和2，最多只能有2个2
    // 背诵数学推导：https://leetcode.cn/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        auto a = n / 3;
        auto b = n % 3;
        if (!b) {
            return (int) pow(3, a);
        }
        if (b == 1) {
            return (int) pow(3, a - 1) * 4;
        }
        return (int) pow(3, a) * 2;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0343_H
