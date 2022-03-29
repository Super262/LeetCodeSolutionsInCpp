//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0788_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0788_H

class Solution {
    // 也要掌握动态规划解法！
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int x = 1; x <= n; ++x) {
            if (isGood(x)) {
                ++ans;
            }
        }
        return ans;
    }

private:
    bool isGood(int x) {
        if (!x) {
            return false;
        }
        bool is_diff = false;
        while (x) {
            auto d = x % 10;
            if (d == 3 || d == 4 || d == 7) {
                return false;
            }
            if (d == 2 || d == 5 || d == 6 || d == 9) {
                is_diff = true;
            }
            x /= 10;
        }
        return is_diff;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0788_H