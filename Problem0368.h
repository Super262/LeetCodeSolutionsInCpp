//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0368_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0368_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 转化成LIS问题
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        const int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int dp[n];
        dp[0] = 0;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] != 0) {
                    continue;
                }
                dp[i] = max(dp[j] + 1, dp[i]);
            }
            if (dp[k] < dp[i]) {
                k = i;
            }
        }
        vector<int> result(1, nums[k]);
        while (dp[k] > 1) {
            for (int i = 0; i < k; ++i) {
                if (dp[i] + 1 != dp[k] || nums[k] % nums[i] != 0) {
                    continue;
                }
                result.push_back(nums[i]);
                k = i;
                break;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0368_H
