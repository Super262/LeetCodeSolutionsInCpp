//
// Created by Fengwei Zhang on 2/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0754_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0754_H

#include <cmath>

using namespace std;

class Solution {
    // 数学，直接背诵：https://leetcode-cn.com/problems/reach-a-number/solution/dao-da-zhong-dian-shu-zi-by-leetcode/
public:
    int reachNumber(int target) {
        if (target == 0) {
            return 0;
        }
        target = abs(target);  // target的正、负情况对结果没有影响
        auto k = (int) sqrt(2ll * target) - 1;
        while ((k + 1ll) * k / 2 < target) {  // 利用求和公式找到满足 s = k*(k+1)/2 >= target 的最小k
            ++k;
        }
        auto d = (int) ((k + 1ll) * k / 2 - target);  // 设D=(a+b+c+...+x)，若更改a～x的符号为负号后满足题意，则target=s-2*D
        while (d % 2) {
            ++k;
            d += k;
        }
        return k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0754_H
