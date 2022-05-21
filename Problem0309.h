//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0309_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0309_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 状态机DP，f[i][0]：已卖出，f[i][1]：已买入，f[i][2]：冷冻期
public:
    int maxProfit(const vector<int> &prices) {
        const auto n = (int) prices.size();
        if (n == 0) {
            return 0;
        }
        int f[3][3];
        memset(f, -0x3f, sizeof f);
        f[0][0] = 0;
        f[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i % 3][0] = max(f[(i - 1) % 3][0], f[(i - 1) % 3][2]);
            f[i % 3][1] = max(f[(i - 1) % 3][1], f[(i - 1) % 3][0] - prices[i]);
            f[i % 3][2] = f[(i - 1) % 3][1] + prices[i];
        }
        return max(f[(n - 1) % 3][2], f[(n - 1) % 3][0]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0309_H
