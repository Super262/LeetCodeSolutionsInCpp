//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0790_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0790_H

#include <cstring>

class Solution {
    // f[i][s]：将0～(i - 1)列全部铺满，第i列的状态为s的方案数
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        int w[4][4] = {{1, 1, 1, 1},
                       {0, 0, 1, 1},
                       {0, 1, 0, 1},
                       {1, 0, 0, 0}};
        int f[n + 1][4];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    f[i][j] = (f[i][j] + f[i - 1][k] * w[k][j]) % MOD;
                }
            }
        }
        return f[n][0];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0790_H
