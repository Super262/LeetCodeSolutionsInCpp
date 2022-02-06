//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0152_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0152_H

#include <vector>

using namespace std;

class Solution {
    // 经典DP，直接背诵
    // dp[i][0]：所有以nums[i]结尾的子数组的乘积的最大值
    // dp[i][1]：所有以nums[i]结尾的子数组的乘积的最小值
public:
    int maxProduct(const vector<int> &nums) {
        const int n = (int) nums.size();
        // 滚动数组优化
        int dp[2][2];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        auto res = dp[0][0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= 0) {
                dp[i % 2][0] = max(nums[i], dp[(i - 1) % 2][0] * nums[i]);
                dp[i % 2][1] = min(nums[i], dp[(i - 1) % 2][1] * nums[i]);
            } else {
                dp[i % 2][0] = max(nums[i], dp[(i - 1) % 2][1] * nums[i]);
                dp[i % 2][1] = min(nums[i], dp[(i - 1) % 2][0] * nums[i]);
            }
            res = max(res, dp[i % 2][0]);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0152_H
