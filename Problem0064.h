//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0064_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0064_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0064 {
public:
    int minPathSum(const vector<vector<int>> &grid) {
        const int n = (int) grid.size();
        const int m = (int) grid[0].size();
        int dp[n][m];
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                }
                if (j) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0064_H
