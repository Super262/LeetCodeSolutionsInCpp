//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0935_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0935_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        // prev[i]：数字i可以从哪些数字转移
        vector<int> prev[] = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        int dp[n][10];  // dp[n - 1][i]：以i结尾、长度为n的路径数量
        memset(dp, 0, sizeof dp);
        for (int i = 0; i <= 9; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (auto p: prev[j]) {
                    dp[i][j] = (int) (((long long) dp[i][j] + dp[i - 1][p]) % 1000000007);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < 10; ++i) {
            result = (int) (((long long) result + dp[n - 1][i]) % 1000000007);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0935_H
