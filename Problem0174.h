//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0174_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0174_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(const vector<vector<int>> &dun) {
        // 已知最终状态（能量大于0），反推初始值
        const int m = (int) dun.size();
        const int n = (int) dun[0].size();
        // 无法用滚动数组优化
        int dp[m][n];  // dp[i][j]：在抵达(i, j)前应保有的能量最小值
        memset(dp, 0x3f, sizeof dp);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = max(1, 1 - dun[i][j]);
                } else {
                    if (i + 1 < m) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] - dun[i][j]);
                    }
                    if (j + 1 < n) {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] - dun[i][j]);
                    }
                    dp[i][j] = max(1, dp[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0174_H
