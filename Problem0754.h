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
        target = abs(target);
        auto k = (int) sqrt(2ll * target) - 1;
        while ((k + 1ll) * k / 2 < target) {
            ++k;
        }
        auto d = (int) ((k + 1ll) * k / 2 - target);
        while (d % 2) {
            ++k;
            d += k;
        }
        return k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0754_H
