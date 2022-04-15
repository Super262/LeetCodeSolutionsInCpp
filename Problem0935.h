//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0935_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0935_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // dp[n][i]：以i结尾、长度为n的路径数量
    // prev[i]：数字i可以从哪些数字转移
public:
    int knightDialer(int n) {
        vector<int> prev[] = {{4, 6},
                              {6, 8},
                              {7, 9},
                              {4, 8},
                              {0, 3, 9},
                              {},
                              {0, 1, 7},
                              {2, 6},
                              {1, 3},
                              {2, 4}};
        int dp[n + 1][10];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i <= 9; ++i) {
            dp[1][i] = 1;
        }
        const int M = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (auto p: prev[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][p]) % M;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans = (ans + dp[n][i]) % M;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0935_H
