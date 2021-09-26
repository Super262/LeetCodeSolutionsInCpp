//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0221_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0221_H

class Problem0221 {
private:
    int maximalSquare(vector <vector<char>> &matrix) {
        // 动态规划问题：dp[i][j]是(i, j)区域内矩形的最大边长
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector <vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int result = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '0') {
                    continue;
                }
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                result = max(result, dp[i][j] * dp[i][j]);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0221_H
