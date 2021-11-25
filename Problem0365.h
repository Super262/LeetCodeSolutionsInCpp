//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0365_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0365_H

class Solution {
    // 目标：ax + by = c（a、b可以小于0）
    // https://www.acwing.com/solution/content/22328/
    //求出 a 与 b 的最大公约数 g，如果 c 能被 g 整除，返回 true。
public:
    bool canMeasureWater(const int &a, const int &b, const int &c) {
        if (c > a + b) {
            return false;
        }
        if (c == 0) {
            return true;
        }
        return c % gcd(a, b) == 0;
    }

private:
    int gcd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0365_H
