//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0198_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0198_H

#include <vector>

using namespace std;

class Problem0198 {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int dp[2];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < (int) nums.size(); ++i) {
            auto a = dp[0];
            auto b = dp[1];
            dp[1] = a + nums[i];
            dp[0] = max(a, b);
        }
        return max(dp[0], dp[1]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0198_H
