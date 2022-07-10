//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0713_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0713_H

#include <vector>

using namespace std;

class Solution {
    // 由于nums中只包含正数，乘积和数组长度正相关，可用"双指针"解决；若nums[l:r]满足乘积小于k，那么nums[l:r]向答案新贡献了(r-l+1)
    // 因为新增加的以nums[r]结尾的子数组有r-l+1个（双指针：r每次右移1，l向左移动以满足题意）
public:
    int numSubarrayProductLessThanK(const vector<int> &nums, int k) {
        int ans = 0;
        int temp = 1;
        for (int l = 0, r = 0; r < (int) nums.size(); ++r) {
            temp *= nums[r];
            while (l <= r && temp >= k) {
                temp /= nums[l];
                ++l;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0713_H
