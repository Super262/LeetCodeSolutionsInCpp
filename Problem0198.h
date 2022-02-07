//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0198_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0198_H

#include <vector>

using namespace std;

class Solution {
    // 经典DP，直接背诵
    // dp[i][0]：不选择第i个房子；dp[i][1]：选择第i个房子
public:
    int rob(const vector<int> &nums) {
        const int n = (int) nums.size();
        // 滚动数组优化
        int dp[2][2];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0]);
            dp[i % 2][1] = dp[(i - 1) % 2][0] + nums[i];
        }
        return max(dp[(n - 1) % 2][0], dp[(n - 1) % 2][1]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0198_H
