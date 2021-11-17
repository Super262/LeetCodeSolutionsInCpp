//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0309_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0309_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxProfit(const vector<int> &prices) {
        const int n = (int) prices.size();
        if (n == 0) {
            return 0;
        }
        int dp[3][3];  // dp[i][0]：冷冻期，dp[i][1]：已买入，dp[i][2]：已卖出
        memset(dp, -0x3f, sizeof dp);
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i % 3][0] = max(dp[(i - 1) % 3][0], dp[(i - 1) % 3][2]);
            dp[i % 3][1] = max(dp[(i - 1) % 3][1], dp[(i - 1) % 3][0] - prices[i]);
            dp[i % 3][2] = dp[(i - 1) % 3][1] + prices[i];
        }
        return max(dp[(n - 1) % 3][2], dp[(n - 1) % 3][0]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0309_H
