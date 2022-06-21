//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0628_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0628_H

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    // 3个数的最大乘积，必然是3个最大的数的乘积或者2个最小的（负）数与最大数的乘积
public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        const auto n = (int) nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n - 1] * nums[0] * nums[1]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0628_H
