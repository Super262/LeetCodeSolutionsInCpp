//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0552_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0552_H

#include <cstring>

using namespace std;

class Solution {
    // dp[i][a][l]：长度为i的序列中包含a个A、结尾有l个连续的L；从前向后枚举
public:
    int checkRecord(int n) {
        const int M = 1000000007;
        int dp[n + 1][2][3];
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 2; ++k) {
                    if (!j) {
                        dp[i + 1][j + 1][0] = (int) (((long long) dp[i + 1][j + 1][0] + dp[i][j][k]) % M);
                    }
                    if (k + 1 <= 2) {
                        dp[i + 1][j][k + 1] = (int) (((long long) dp[i + 1][j][k + 1] + dp[i][j][k]) % M);
                    }
                    dp[i + 1][j][0] = (int) (((long long) dp[i + 1][j][0] + dp[i][j][k]) % M);
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                res = (int) (((long long) res + dp[n][j][k]) % M);
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0552_H
