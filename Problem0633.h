//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0633_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0633_H

#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int b = 0; (long long) b * b <= c; ++b) {
            auto x = c - b * b;
            auto a = (int) sqrt(x);
            if (a * a == x) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0633_H
