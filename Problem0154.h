//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0154_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0154_H

#include <vector>

using namespace std;

class Solution {
    // 在最坏情况下，如果数组中的元素完全相同，那么 while 循环就需要执行 n 次，每次忽略区间的右端点，时间复杂度为 O(n)。
public:
    int findMin(const vector<int> &nums) {
        auto r = (int) nums.size() - 1;
        while (r > 0 && nums[0] == nums[r]) {  // 忽略边界的重复元素
            --r;
        }
        if (nums[r] > nums[0]) {  // 数组正序
            return nums[0];
        }
        int l = 0;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] < nums[0]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[r];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0154_H
