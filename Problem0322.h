//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0322_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0322_H

#include <vector>

using namespace std;

class Problem0322 {
public:
    int coinChange(vector<int> &coins, int amount) {
        int dp[amount + 1];
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int num: coins) {
            for (int i = num; i <= amount; ++i) {
                dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
        if (dp[amount] == 0x3f3f3f3f) {
            return -1;
        }
        return dp[amount];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0322_H
