//
// Created by Fengwei Zhang on 10/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0673_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0673_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(const vector<int> &nums) {
        const int n = (int) nums.size();
        int dp[n], g[n];  // dp[i]表示以nums[i]结尾的LIS的最大长度，g[i]表示以nums[i]结尾的LIS的个数
        int max_l = 0, max_cnt = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            g[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= nums[i]) {
                    continue;
                }
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    g[i] = g[j];
                } else if (dp[i] == dp[j] + 1) {
                    g[i] += g[j];
                }
            }
            if (dp[i] > max_l) {
                max_l = dp[i];
                max_cnt = g[i];
            } else if (dp[i] == max_l) {
                max_cnt += g[i];
            }
        }
        return max_cnt;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0673_H
