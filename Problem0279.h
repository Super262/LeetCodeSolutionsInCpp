//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0279_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0279_H

#include <cmath>

using namespace std;

class Solution {
    // 四平方和定理，背诵并讲通推导过程
    // https://www.acwing.com/solution/content/300/
public:
    int numSquares(int n) {
        if (checkNum(n)) {
            return 1;
        }
        for (int x = 1; x <= n / x; ++x) {
            if (checkNum(n - x * x)) {
                return 2;
            }
        }
        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 != 7) {
            return 3;
        }
        return 4;
    }

private:
    bool checkNum(const int &x) {
        auto r = (int) sqrt(x);
        return r * r == x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0279_H
