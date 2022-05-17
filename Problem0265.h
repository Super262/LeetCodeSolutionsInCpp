//
// Created by Fengwei Zhang on 5/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0265_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0265_H

#include <vector>

using namespace std;

class Solution {
    // f[i][j]：将0～i号房子粉刷好、第i号房子颜色为j的总花费
    // 大幅优化时间复杂度：若为第i行选择颜色j，j只和上行（i-1）的最小值、次小值相关，无需遍历所有m个颜色
public:
    int minCostII(const vector<vector<int>> &costs) {
        const auto n = (int) costs.size();
        const auto m = (int) costs[0].size();
        int f[2][m];
        for (int i = 0; i < m; ++i) {
            f[0][i] = costs[0][i];
        }
        for (int i = 1; i < n; ++i) {
            int second_min = -1;
            int first_min = -1;
            for (int j = 0; j < m; ++j) {
                if (first_min == -1 || f[(i - 1) % 2][j] < f[(i - 1) % 2][first_min]) {
                    second_min = first_min;
                    first_min = j;
                } else if (second_min == -1 || f[(i - 1) % 2][j] < f[(i - 1) % 2][second_min]) {
                    second_min = j;
                }
            }
            memset(f[i % 2], 0x3f, sizeof f[i % 2]);
            for (int j = 0; j < m; ++j) {
                if (j == first_min) {
                    f[i % 2][j] = min(f[i % 2][j], f[(i - 1) % 2][second_min] + costs[i][j]);
                } else {
                    f[i % 2][j] = min(f[i % 2][j], f[(i - 1) % 2][first_min] + costs[i][j]);
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, f[(n - 1) % 2][i]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0265_H
