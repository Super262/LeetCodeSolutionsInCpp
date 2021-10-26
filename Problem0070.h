//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0070_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0070_H

class Problem0070 {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        dp[1] = dp[0] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0070_H
