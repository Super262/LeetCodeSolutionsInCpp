//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0132_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0132_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int minCut(const string &s) {
        const int n = (int) s.size();
        bool st[n][n];  // st[i][j]：s[i][j]是否为回文串
        memset(st, 0, sizeof st);
        for (int r = 0; r < n; ++r) {
            for (int l = r; l >= 0; --l) {
                if (l == r) {
                    st[l][r] = true;
                } else {
                    st[l][r] = s[l] == s[r] && (l + 1 > r - 1 || st[l + 1][r - 1]);
                }
            }
        }
        int dp[n + 1];  // dp[i]：前i个字符最少分为dp[i]个回文串（i >= 1）
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int r = 1; r <= n; ++r) {
            for (int l = 1; l <= r; ++l) {
                if (!st[l - 1][r - 1]) {
                    continue;
                }
                dp[r] = min(dp[l - 1] + 1, dp[r]);
            }
        }
        return dp[n] - 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0132_H
