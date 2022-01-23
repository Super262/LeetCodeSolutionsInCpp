//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0479_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0479_H

#include <cmath>
#include <string>

using namespace std;

class Solution {
    // 暴力枚举，但要有技巧：枚举回文数的因子
    // 经观察，我们发现：当1<=n<=9时，2个n位数相乘的结果是2*n位数或(2*n-1)数；f*f <= ff
public:
    int largestPalindrome(int n) {
        if (n == 1) {  // 特殊值
            return 9;
        }
        auto f = (int) pow(10, n) - 1;
        for (auto i = f; i > 0; --i) {
            auto a = to_string(i);
            auto b = string(a.rbegin(), a.rend());
            auto num = stoll(a + b);
            for (long long j = f; j >= num / f; --j) {
                if (num % j) {
                    continue;
                }
                return (int) (num % 1337);
            }
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0479_H
