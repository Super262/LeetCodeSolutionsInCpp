//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0583_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0583_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int minDistance(const string &w1, const string &w2) {
        const auto n = (int) w1.size();
        const auto m = (int) w2.size();
        int dp[n + 1][m + 1];
        memset(dp, 0x3f, sizeof dp);
        for (int l = 0; l <= m; ++l) {
            dp[0][l] = l;
        }
        for (int l = 0; l <= n; ++l) {
            dp[l][0] = l;
        }
        for (int l1 = 1; l1 <= n; ++l1) {
            for (int l2 = 1; l2 <= m; ++l2) {
                dp[l1][l2] = min(dp[l1 - 1][l2], dp[l1][l2 - 1]) + 1;
                if (w1[l1 - 1] != w2[l2 - 1]) {
                    continue;
                }
                dp[l1][l2] = min(dp[l1][l2], dp[l1 - 1][l2 - 1]);
            }
        }
        return dp[n][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0583_H
