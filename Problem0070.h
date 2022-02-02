//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0070_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0070_H

class Solution {
public:
    int climbStairs(int n) {  // 滑动窗口优化
        int dp[3];
        dp[1] = dp[0] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
        }
        return dp[n % 3];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0070_H
