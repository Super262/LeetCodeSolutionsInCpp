//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0714_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0714_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 状态机DP：f[i][0]表示无股票，f[i][1]表示有股票
public:
    int maxProfit(const vector<int> &prices, int fee) {
        const auto n = (int) prices.size();
        int f[2][2];
        int res = 0;
        memset(f, -0x3f, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i % 2][0] = max(f[(i - 1) % 2][0], f[(i - 1) % 2][1] + prices[i - 1]);
            f[i % 2][1] = max(f[(i - 1) % 2][1], f[(i - 1) % 2][0] - prices[i - 1] - fee);
            res = max(res, f[i % 2][0]);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0714_H
