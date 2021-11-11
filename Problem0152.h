//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0152_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0152_H

#include <vector>

using namespace std;

class Problem0152 {
public:
    int maxProduct(const vector<int> &nums) {
        const int n = (int) nums.size();
        int dp[n][2];  // dp[i][0]：所有以nums[i]结尾的子数组的乘积的最大值；dp[i][1]：所有以nums[i]结尾的子数组的乘积的最小值
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= 0) {
                dp[i][0] = max(nums[i], dp[i - 1][0] * nums[i]);
                dp[i][1] = min(nums[i], dp[i - 1][1] * nums[i]);
            } else {
                dp[i][0] = max(nums[i], dp[i - 1][1] * nums[i]);
                dp[i][1] = min(nums[i], dp[i - 1][0] * nums[i]);
            }
        }
        int result = dp[0][0];
        for (int i = 1; i < n; ++i) {
            result = max(result, dp[i][0]);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0152_H
