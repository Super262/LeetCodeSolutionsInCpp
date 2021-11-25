//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0375_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0375_H

#include <cstring>

using namespace std;

class Solution {
    // dp[i][j]：目标值 i <= x <= j 时，所有猜法中最坏情况的最小值
public:
    int getMoneyAmount(const int &n) {
        int dp[n + 2][n + 2];
        memset(dp, 0, sizeof dp);  // 注意，初始值为0：区间[i:j]中有1个或更少的数时（i >= j），代价为0
        for (int len = 2; len <= n; ++len) {
            for (int st = 1; st + len - 1 <= n; ++st) {
                auto ed = st + len - 1;
                dp[st][ed] = INT_MAX;
                for (int k = st; k <= ed; ++k) {
                    dp[st][ed] = min(dp[st][ed], max(dp[st][k - 1], dp[k + 1][ed]) + k);
                }
            }
        }
        return dp[1][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0375_H
