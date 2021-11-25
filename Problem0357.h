//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0357_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0357_H

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        n = min(n, 10);
        int dp[2];
        dp[0] = 1;
        dp[1] = 9;
        int result = dp[0] + dp[1];
        for (int i = 2; i <= n; ++i) {
            dp[i % 2] = dp[(i - 1) % 2] * (11 - i);
            result += dp[i % 2];
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0357_H
