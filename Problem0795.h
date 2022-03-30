//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0795_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0795_H

#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(const vector<int> &nums, int left, int right) {
        return (int) (countSubArrays(nums, right) - countSubArrays(nums, left - 1));
    }

private:
    long long countSubArrays(const vector<int> &nums, int limit) {
        long long ans = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (nums[i] > limit) {
                continue;
            }
            auto j = i + 1;
            while (j < (int) nums.size() && nums[j] <= limit) {
                ++j;
            }
            auto k = j - i;
            ans += (long long) (k + 1) * k / 2;  // 长度为k的数组有 (k + 1) * k / 2 个非空子数组
            i = j - 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0795_H
