//
// Created by Fengwei Zhang on 6/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0562_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0562_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 动态规划，f[i][j][k]表示终点为(i,j)，方向为k的直线的最大长度（k=0，向下；k=1，向右；k=2，对角线；k=3，反对角线）
public:
    int longestLine(const vector<vector<int>> &mat) {
        const auto m = (int) mat.size();
        const auto n = (int) mat[0].size();
        int ans = 0;
        int f[m][n][4];
        memset(f, 0, sizeof f);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!mat[i][j]) {
                    continue;
                }
                f[i][j][0] = 1;
                f[i][j][1] = 1;
                f[i][j][2] = 1;
                f[i][j][3] = 1;
                ans = max(1, ans);
                if (i - 1 >= 0) {
                    f[i][j][0] = max(f[i][j][0], f[i - 1][j][0] + 1);
                    ans = max(ans, f[i][j][0]);
                }
                if (j - 1 >= 0) {
                    f[i][j][1] = max(f[i][j][1], f[i][j - 1][1] + 1);
                    ans = max(ans, f[i][j][1]);
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    f[i][j][2] = max(f[i][j][2], f[i - 1][j - 1][2] + 1);
                    ans = max(ans, f[i][j][2]);
                }
                if (i - 1 >= 0 && j + 1 < n) {
                    f[i][j][3] = max(f[i][j][3], f[i - 1][j + 1][3] + 1);
                    ans = max(ans, f[i][j][3]);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0562_H
