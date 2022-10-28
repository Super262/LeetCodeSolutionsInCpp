//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0029_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0029_H

#include <vector>

using namespace std;

class Problem0029 {
    // 直接背诵，贪心算法：https://www.acwing.com/solution/content/15056/
    // 设除数为y、被除数为x，x=t*y+r；设n为满足(2^n)*y<=x的最大值；
    // 从大到小枚举i（0 <= i <= n），若(2^i)*y<=x，将2^i加入结果ans中，更新x=x-(2^i)*y
public:
    int divide(const int dividend, const int divisor) {
        long long a = dividend;
        long long b = divisor;
        bool is_neg = false;
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
            is_neg = true;
        }
        a = abs(a);
        b = abs(b);
        vector<long long> exps;  // (2^i) * b;
        for (auto e = b; e <= a; e *= 2) {
            exps.emplace_back(e);
        }
        long long result = 0;
        for (int i = (int) exps.size() - 1; i >= 0; --i) {
            if (exps[i] > a) {
                continue;
            }
            a -= exps[i];
            result += 1ll << i;  // 非常重要的细节，类型转换防止溢出（不是"1"而是"1ll"）
        }
        if (is_neg) {
            result = -result;
        }
        if (result < INT_MIN || result > INT_MAX) {
            return INT_MAX;
        }
        return (int) result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0029_H
