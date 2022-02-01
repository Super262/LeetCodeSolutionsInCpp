//
// Created by Fengwei Zhang on 10/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0050_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0050_H

#include <algorithm>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {  // 快速幂，背诵
        double res = 1;
        for (long long k = abs((long long) n); k > 0; k >>= 1) {
            if (k & 1) {
                res *= x;
            }
            x *= x;
        }
        if (n < 0) {
            return 1 / res;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0050_H
