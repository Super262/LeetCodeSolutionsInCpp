//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0633_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0633_H

#include <cmath>

using namespace std;

class Solution {
    // 根据题意，可知0<=b^2<=c，我们枚举b，计算出a=sqrt(c-b^2)，判断a是否为整数
public:
    bool judgeSquareSum(int c) {
        for (int b = 0; (long long) b * b <= c; ++b) {
            auto a = sqrt(c - b * b);
            if (a == (int) a) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0633_H
