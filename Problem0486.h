//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0486_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0486_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 区间动态规划解决博弈论问题
public:
    bool PredictTheWinner(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int dp[n][n];
        memset(dp, -0x3f, sizeof dp);
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                auto j = i + length - 1;
                dp[i][j] = max(dp[i][j], max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]));
            }
        }
        return dp[0][n - 1] >= 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0486_H
