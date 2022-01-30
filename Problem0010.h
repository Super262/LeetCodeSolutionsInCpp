//
// Created by Fengwei Zhang on 10/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0010_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0010_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // dp[i][j]：s的前i个字符是否能匹配p的前j个字符（i, j >= 1）
    // https://www.acwing.com/solution/content/557/
public:
    bool isMatch(const string &s, const string &p) {
        const int n = (int) s.size();
        const int m = (int) p.size();
        bool dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = true;  // 不要忘记初始化
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j + 1 <= m && p[j] == '*') {  // 将后面的'*'和当前字符当作一个整体
                    continue;
                }
                if (i && p[j - 1] != '*') {  // 单字匹配
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else if (p[j - 1] == '*') { // 采用类似于完全背包问题的优化方案
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }
        return dp[n][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0010_H
