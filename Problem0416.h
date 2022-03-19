//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0416_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0416_H

#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class Solution {
    // 转化为背包问题：是否能装满容量为m / 2的背包
public:
    bool canPartition(const vector<int> &nums) {
        auto m = accumulate(nums.begin(), nums.end(), 0);
        if (m % 2) {
            return false;
        }
        bool dp[m + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = true;
        for (const auto &x: nums) {
            for (auto j = m; j >= x; --j) {
                dp[j] |= dp[j - x];
            }
        }
        return dp[m / 2];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0416_H
