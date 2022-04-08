//
// Created by Fengwei Zhang on 4/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0877_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0877_H

#include <vector>

using namespace std;

class Solution {
    // 每次选择都是最坏情况下的最优解
    // 区间DP，f[i][j] = A - B，表示两人从piles[i:j]中选取石子后，双方石子的差值（A先手）
public:
    bool stoneGame(const vector<int> &piles) {
        const auto n = (int) piles.size();
        int f[n][n];
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                auto j = i + len - 1;
                if (len == 1) {
                    f[i][j] = piles[i];
                } else {
                    f[i][j] = max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1]);
                }
            }
        }
        return f[0][n - 1] > 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0877_H
