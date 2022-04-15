//
// Created by Fengwei Zhang on 4/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0931_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0931_H

#include <vector>

using namespace std;

class Solution {
    // 经典DP，类似数字三角形：f[i][j] = matrix[i][j] + min(f[i - 1][j], f[i - 1][j - 1], f[i - 1][j + 1])
public:
    int minFallingPathSum(const vector<vector<int>> &matrix) {
        const auto m = (int) matrix.size();
        const auto n = (int) matrix[0].size();
        int f[m][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i][j] = matrix[i][j];
                if (i - 1 < 0) {
                    continue;
                }
                f[i][j] += min(f[i - 1][j], min(f[i - 1][max(0, j - 1)], f[i - 1][min(n - 1, j + 1)]));
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, f[n - 1][j]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0931_H
