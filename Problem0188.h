//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0188_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0188_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxProfit(const int &k, const vector<int> &prices) {
        const int n = (int) prices.size();
        int dp[2][n + 1][k + 1];
        int result = 0;
        memset(dp, -0x3f, sizeof dp);
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[0][i][j] = max(dp[0][i - 1][j], dp[1][i - 1][j] + prices[i - 1]);
                result = max(result, dp[0][i][j]);
                dp[1][i][j] = dp[1][i - 1][j];
                if (j > 0) {
                    dp[1][i][j] = max(dp[1][i][j], dp[0][i - 1][j - 1] - prices[i - 1]);
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0188_H
