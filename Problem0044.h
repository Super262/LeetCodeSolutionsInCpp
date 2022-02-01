//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0044_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0044_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // dp[i][j]描述s的前i个字符和p的前j个字符的匹配情况（i,j >= 1）
    // 优化：借鉴完全背包问题的思想
public:
    bool isMatch(const string &s, const string &p) {
        const int n = (int) s.size();
        const int m = (int) p.size();
        bool dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = true;  // 初始化：两个空串，匹配成功
        for (int i = 1; i <= m; ++i) {  // 初始化："*"可以匹配任意字符串
            if (p[i - 1] != '*') {
                break;
            }
            dp[0][i] = true;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0044_H
