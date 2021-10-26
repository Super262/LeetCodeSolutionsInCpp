//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0063_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0063_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0063 {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        const int m = (int) obstacleGrid.size();
        const int n = (int) obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) { // 注意边界情况（输入数据为[[1]]）
            return 0;
        }
        int dp[m][n];
        dp[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0]) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i]) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = 0;
                if (obstacleGrid[i][j]) {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0063_H
