//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0063_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0063_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>> &obstacle_grid) {
        const int m = (int) obstacle_grid.size();
        const int n = (int) obstacle_grid[0].size();
        if (obstacle_grid[0][0] || obstacle_grid[m - 1][n - 1]) { // 注意边界情况（输入数据为[[1]]）
            return 0;
        }
        int f[m][n];
        f[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (obstacle_grid[i][0]) {
                f[i][0] = 0;
            } else {
                f[i][0] = f[i - 1][0];
            }
        }
        for (int i = 1; i < n; ++i) {
            if (obstacle_grid[0][i]) {
                f[0][i] = 0;
            } else {
                f[0][i] = f[0][i - 1];
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = 0;
                if (obstacle_grid[i][j]) {
                    continue;
                }
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0063_H
