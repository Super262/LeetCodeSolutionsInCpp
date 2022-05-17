//
// Created by Fengwei Zhang on 5/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0256_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0256_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // f[i][j]：将0～i号房子粉刷好、第i号房子颜色为j的总花费
    // 巧妙优化：LeetCode 265
public:
    int minCost(const vector<vector<int>> &costs) {
        const auto n = (int) costs.size();
        const auto m = (int) costs[0].size();
        int f[2][m];
        for (int i = 0; i < m; ++i) {
            f[0][i] = costs[0][i];
        }
        for (int i = 1; i < n; ++i) {
            memset(f[i % 2], 0x3f, sizeof f[i % 2]);
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (k == j) {
                        continue;
                    }
                    f[i % 2][j] = min(f[i % 2][j], f[(i - 1) % 2][k] + costs[i][j]);
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0256_H
