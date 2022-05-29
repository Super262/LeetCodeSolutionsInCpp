//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0413_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0413_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 差分数组的应用，设diff[i]=nums[i]-nums[i-1]，我们要统计长度至少为3的子数组nums[i:j]的个数，满足diff[i+1:j]内元素相等
    // 长度为k的数组，有(1+2+...+(k-1))个长度不小于2的子数组
public:
    int numberOfArithmeticSlices(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int diff[n];  // 差分数组
        memset(diff, 0, sizeof diff);
        diff[0] = nums[0];
        for (auto i = n - 1; i >= 1; --i) {
            diff[i] = nums[i] - nums[i - 1];
        }
        int ans = 0;
        // 若原数组[i:j]是等差数列，则差分数组[i + 1:j]所有元素相等
        for (int l = 1; l < n; ++l) {
            auto r = l;
            while (r < n && diff[r] == diff[l]) {
                ++r;
            }
            auto k = r - l;
            ans += k * (k - 1) / 2;
            l = r - 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0413_H
