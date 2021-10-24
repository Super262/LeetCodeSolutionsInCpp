//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0029_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0029_H

#include <vector>

using namespace std;

class Problem0029 {
public:
    int divide(const int &dividend, const int &divisor) {
        long long a = dividend;
        long long b = divisor;
        bool isNeg = false;
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
            isNeg = true;
        }
        a = abs(a);
        b = abs(b);
        vector<long long> exps;  // (2^i) * b;
        for (auto e = b; e <= a; e <<= 1) {
            exps.emplace_back(e);
        }
        long long result = 0;
        for (int i = (int) exps.size() - 1; i >= 0; --i) {
            if (exps[i] > a) {
                continue;
            }
            a -= exps[i];
            result += 1ll << i;  // Don't use "1 << i" instead of "1ll << 1"!
        }
        if (isNeg) {
            result = -result;
        }
        if (result < INT_MIN || result > INT_MAX) {
            return INT_MAX;
        }
        return (int) result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0029_H
