//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0153_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0153_H

#include <vector>

using namespace std;

class Solution {
    // 旋转后的数组的最小值在"分界点"处
public:
    int findMin(const vector<int> &nums) {
        auto r = (int) nums.size() - 1;
        if (nums[r] > nums[0]) {  // 数组元素单调递增
            return nums[0];
        }
        int l = 0;
        while (l < r) {  // 查找分界点
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0153_H
