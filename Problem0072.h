//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0072_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0072_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int minDistance(const string &a, const string &b) {
        if (a.empty()) {
            return (int) b.size();
        }
        if (b.empty()) {
            return (int) a.size();
        }
        const auto m = (int) a.size();
        const auto n = (int) b.size();
        int dp[m + 1][n + 1];
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);  // 可能无需操作
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);  // 修改a或b的最后一个字符使它们匹配
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);  // 为匹配a[i]，在b的末尾插入新字符
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);  // 为匹配b[i]，在a的末尾插入新字符
            }
        }
        return dp[m][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0072_H
