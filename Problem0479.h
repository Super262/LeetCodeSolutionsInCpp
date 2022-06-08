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
    // 设f是最大的n位数，nf是最大的n-1位数；设x是n位数，rx是x反序后得到的数，易知数字y=("x"+"rx")是回文数
    // 若我们能找到y的因子j，满足nf<j<=f、nf<y/j<=f，那么y是合法的；因为我们要得到最大的y，我们从f开始枚举x到nf+1
public:
    int largestPalindrome(int n) {
        if (n == 1) {  // 特殊值
            return 9;
        }
        const auto f = (int) pow(10, n) - 1;
        const auto nf = f / 10;
        for (auto i = f; i > nf; --i) {
            auto a = to_string(i);
            auto num = stoll(a + string(a.rbegin(), a.rend()));
            for (auto j = f; j >= num / j && j > nf; --j) {
                if (num % j) {
                    continue;
                }
                if (num / j <= nf) {
                    continue;
                }
                return (int) (num % 1337);
            }
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0479_H
