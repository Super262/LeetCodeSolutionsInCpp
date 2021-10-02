//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0044_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0044_H

#include <string>
#include <cstring>

using namespace std;

class Problem0044 {
    // 优化：借鉴完全背包问题的思想
private:
    bool isMatch(string s, string p) {
        const int n = (int) s.size();
        const int m = (int) p.size();
        s = ' ' + s;
        p = ' ' + p;
        bool dp[n + 1][m + 1];  // dp[i][j]描述s[1~i]和p[1~j]的匹配情况
        memset(dp, 0, sizeof dp);
        dp[0][0] = true;  // 两个空串，匹配成功
        for (int i = 0; i <= n; ++i) {  // i从0开始，因为dp[0][j]有意义
            for (int j = 1; j <= m; ++j) {  // j从1开始，因为dp[i][0]无意义
                if (p[j] == '*') {
                    dp[i][j] = dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
                } else {
                    dp[i][j] = (s[i] == p[j] || p[j] == '?') && i > 0 && dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0044_H
