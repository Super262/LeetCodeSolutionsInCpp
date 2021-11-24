//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0329_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0329_H

#include <vector>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(const vector<vector<int>> &matrix) {
        const int m = (int) matrix.size();
        const int n = (int) matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int result = -1;
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result = max(result, dfs(i, j, matrix, dp, dx, dy));
            }
        }
        return result;
    }

private:
    int dfs(const int &x,
            const int &y,
            const vector<vector<int>> &matrix,
            vector<vector<int>> &dp,
            const int dx[],
            const int dy[]) {
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        dp[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size() || matrix[nx][ny] <= matrix[x][y]) {
                continue;
            }
            dp[x][y] = max(dp[x][y], dfs(nx, ny, matrix, dp, dx, dy) + 1);
        }
        return dp[x][y];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0329_H
