//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0518_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0518_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int change(const int amount, const vector<int> &coins) {
        int dp[amount + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (const auto &x: coins) {
            for (int v = x; v <= amount; ++v) {
                dp[v] += dp[v - x];
            }
        }
        return dp[amount];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0518_H
