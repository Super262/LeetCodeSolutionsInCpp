//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0064_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0064_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int minPathSum(const vector<vector<int>> &grid) {
        const int m = (int) grid.size();
        const int n = (int) grid[0].size();
        int f[m][n];
        memset(f, 0x3f, sizeof f);
        f[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i) {
                    f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                }
                if (j) {
                    f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
                }
            }
        }
        return f[m - 1][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0064_H
