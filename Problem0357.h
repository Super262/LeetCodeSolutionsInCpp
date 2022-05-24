//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0357_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0357_H

#include <iostream>

using namespace std;

class Solution {
    // 动态规划，f[i]表示不含重复数字的i位数的个数（最高位不为0）
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int f[2];
        f[1] = 9;
        auto ans = 1 + f[1];  // 别忘记加上"0"
        for (int i = 2; i <= n; ++i) {
            f[i % 2] = f[(i - 1) % 2] * (10 - (i - 1));  // 当前位有(10-(i-1))种选择
            ans += f[i % 2];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0357_H
