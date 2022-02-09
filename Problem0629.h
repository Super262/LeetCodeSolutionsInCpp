//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0629_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0629_H

#include <cstring>

using namespace std;

class Solution {
    // 经典DP，必须掌握，注意优化：https://www.acwing.com/solution/content/483/
    // dp[i][j]：由1～i构成的包含j个逆序对的所有排列
public:
    int kInversePairs(const int n, const int k) {
        const int M = 1e9 + 7;
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof dp);
        dp[1][0] = 1;  // 初始化：i=1时，仅当j=0时存在有效排列
        for (int i = 2; i <= n; ++i) {
            long long s = 0;
            for (int j = 0; j <= k; ++j) {
                s += dp[i - 1][j];
                if (j >= i) {
                    s -= dp[i - 1][j - i];
                }
                dp[i][j] = (int) (s % M);
            }
        }
        return (dp[n][k] + M) % M;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0629_H
