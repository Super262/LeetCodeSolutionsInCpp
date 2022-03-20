//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0368_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0368_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 转化成LIS问题：先排序
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        const auto n = (int) nums.size();
        int dp[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] != 0) {
                    continue;
                }
                dp[i] = max(dp[j] + 1, dp[i]);
            }
            if (dp[ans] < dp[i]) {
                ans = i;
            }
        }
        vector<int> result(1, nums[ans]);
        while (dp[ans] > 1) {
            for (int i = 0; i < ans; ++i) {
                if (dp[i] + 1 != dp[ans] || nums[ans] % nums[i] != 0) {
                    continue;
                }
                result.push_back(nums[i]);
                ans = i;
                break;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0368_H
