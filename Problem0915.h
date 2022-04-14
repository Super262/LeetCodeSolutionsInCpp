//
// Created by Fengwei Zhang on 4/13/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0915_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0915_H

#include <vector>

using namespace std;

class Solution {
    // 预处理出前缀最大值p[i]，p[i]表示[0:i]段最大值；从后向前枚举i，边更新后缀最小值，边更新答案
public:
    int partitionDisjoint(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int suffix_min[n];
        suffix_min[n - 1] = nums[n - 1];
        for (auto i = n - 2; i >= 0; --i) {
            suffix_min[i] = min(nums[i], suffix_min[i + 1]);
        }
        for (int i = 0, lm = INT_MIN; i + 1 < n; ++i) {
            lm = max(lm, nums[i]);
            if (lm <= suffix_min[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0915_H
