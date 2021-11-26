//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0377_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0377_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 类似于完全背包问题：https://www.acwing.com/solution/content/5005/
    // 如果此题用完全背包解答，则会将顺序不同的序列算作相同的组合
public:
    int combinationSum4(vector<int> &nums, const int &target) {
        unsigned long long dp[target + 1];  // 防止溢出！
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int j = 0; j <= target; ++j) {  //  dp[j]表示表示组成和为j的方案数，所以外层循环为j
            for (const auto &x: nums) {
                if (j < x) {
                    continue;
                }
                dp[j] += dp[j - x];
            }
        }
        return (int) dp[target];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0377_H