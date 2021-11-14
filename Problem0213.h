//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0213_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0213_H

#include <vector>

using namespace std;

class Solution {
public:
    int rob(const vector<int> &nums) {
        // https://www.acwing.com/solution/content/19758/
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        const int n = (int) nums.size();
        int result = 0;
        // 滚动数组优化
        int dp[2][2];  // dp[i % 2][0]：盗取第i个时的最大获利；dp[i % 2][1]：不盗取第i个时的最大获利

        // Choose the first one: [0, n - 2]
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]);
            dp[i % 2][1] = dp[(i - 1) % 2][0] + nums[i];
        }
        result = max(dp[(n - 2) % 2][0], dp[(n - 2) % 2][1]);

        // Do not choose the first one: [1, n - 1]
        dp[1][0] = 0;
        dp[1][1] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]);
            dp[i % 2][1] = dp[(i - 1) % 2][0] + nums[i];
        }
        result = max(max(dp[(n - 1) % 2][0], dp[(n - 1) % 2][1]), result);

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0213_H
