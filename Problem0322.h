//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0322_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0322_H

#include <vector>

using namespace std;

class Solution {
    // 背包问题，f[i]表示构成价值为i的总额时的方案数
public:
    int coinChange(const vector<int> &coins, int amount) {
        int f[amount + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (const auto &num: coins) {
            for (int i = num; i <= amount; ++i) {
                f[i] = min(f[i], f[i - num] + 1);
            }
        }
        if (f[amount] == 0x3f3f3f3f) {
            return -1;
        }
        return f[amount];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0322_H
