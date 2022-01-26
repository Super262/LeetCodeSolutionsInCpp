//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0546_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0546_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // dp[i][j][k]：将[i:j]清空，最后删除i，且最后删除k个盒子的所有方案（注意：本题最后被删掉的部分不一定是后缀）中的最大积分
    // https://www.acwing.com/solution/content/6168/
public:
    int removeBoxes(vector<int> &boxes) {
        const auto n = (int) boxes.size();
        int dp[n][n][n + 1];
        int g[n][n];  // g[i][j]为所有f[i][j][k]的最大值
        memset(dp, -0x3f, sizeof dp);
        memset(g, -0x3f, sizeof g);
        for (int i = 0; i < n; ++i) {
            dp[i][i][1] = 1;
            dp[i][i][0] = 0;
            g[i][i] = 1;
        }
        for (int i = 1; i < n; ++i) {  // 这个特殊初值会被用到
            g[i][i - 1] = 0;
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                auto j = i + length - 1;
                dp[i][j][1] = 1 + g[i + 1][j];
                for (auto p = i + 1; p <= j; ++p) {
                    if (boxes[i] != boxes[p]) {
                        continue;
                    }
                    for (int k = 2; k <= length; ++k) {
                        dp[i][j][k] = max(dp[i][j][k], g[i + 1][p - 1] + dp[p][j][k - 1] - (k - 1) * (k - 1) + k * k);
                    }
                }
                for (int k = 1; k <= length; ++k) {
                    g[i][j] = max(g[i][j], dp[i][j][k]);
                }
            }
        }
        return g[0][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0546_H
