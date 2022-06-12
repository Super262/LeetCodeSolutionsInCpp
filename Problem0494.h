//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0494_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0494_H

#include <vector>
#include <numeric>
#include <cstring>

using namespace std;

class Solution {
    // 转化为背包问题：设所有整数和为sum，添加负号的整数的和为neg，添加正号的整数的和为 sum - neg，
    // target = (sum - neg) - neg，由等式可以推出 neg = (sum - target) / 2
    // 如果 sum - target 为负数或奇数，无解
public:
    int findTargetSumWays(const vector<int> &nums, int target) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum - target < 0 || (sum - target) % 2) {
            return 0;
        }
        auto neg = (sum - target) / 2;
        int f[neg + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (const auto &x: nums) {
            for (int j = neg; j >= x; --j) {
                f[j] += f[j - x];
            }
        }
        return f[neg];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0494_H
