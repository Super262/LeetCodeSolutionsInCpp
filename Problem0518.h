//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0518_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0518_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 转化为完全背包问题：f[i]表示凑出i的方案数，f[0]=1
public:
    int change(const int amount, const vector<int> &coins) {
        int f[amount + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (const auto &x: coins) {
            for (int v = x; v <= amount; ++v) {
                f[v] += f[v - x];
            }
        }
        return f[amount];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0518_H
