//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0516_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0516_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 区间DP：dp[i][j]表示s[i:j]段回文子序列最大长度
public:
    int longestPalindromeSubseq(const string &s) {
        const auto n = (int) s.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                auto j = i + length - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                }
                dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i + 1][j]));
            }
        }
        return dp[0][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0516_H
