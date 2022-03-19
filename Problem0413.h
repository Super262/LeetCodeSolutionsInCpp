//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0413_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0413_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(const vector<int> &nums) {
        auto n = (int) nums.size();
        int dif[n];  // 差分数组
        memset(dif, 0, sizeof dif);
        dif[0] = nums[0];
        for (auto i = n - 1; i >= 1; --i) {
            dif[i] = nums[i] - nums[i - 1];
        }
        int res = 0;
        // 注意：若原数组[i:j]是等差数列，则差分数组[i + 1:j]所有元素相等
        for (int l = 1; l < n; ++l) {
            auto r = l;
            while (r < n && dif[r] == dif[l]) {
                ++r;
            }
            auto k = r - l;
            res += k * (k - 1) / 2;  // 长度为k的等差数列，有(1 + 2 + ... + k - 1)个长度不小于2的等差子数列
            l = r - 1;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0413_H
