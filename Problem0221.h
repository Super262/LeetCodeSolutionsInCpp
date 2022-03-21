//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0221_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0221_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 经典算法，必须掌握
    // 动态规划问题：f[i][j]是(i, j)区域内矩形的最大边长
public:
    int maximalSquare(const vector<vector<char>> &matrix) {
        const auto m = (int) matrix.size();
        const auto n = (int) matrix[0].size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '0') {
                    continue;
                }
                f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
                ans = max(ans, f[i][j] * f[i][j]);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0221_H
