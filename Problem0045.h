//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0045_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0045_H

#include <vector>

using namespace std;

class Problem0045 {
public:
    int jump(const vector<int> &nums) {
        int dp[nums.size()];
        dp[0] = 0;
        for (int r = 1, l = 0; r < (int) nums.size(); ++r) {
            while (l < r && l + nums[l] < r) {
                ++l;
            }
            dp[r] = dp[l] + 1;
        }
        return dp[nums.size() - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0045_H
