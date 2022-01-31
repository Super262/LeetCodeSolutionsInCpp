//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0035_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0035_H

#include <vector>

using namespace std;

class Solution {
    // 二分查找大于等于目标值的第一个位置
    // 直接背诵，注意细节
public:
    int searchInsert(const vector<int> &nums, const int target) {
        int l = 0;
        int r = (int) nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[r] >= target) {
            return r;
        }
        return (int) nums.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0035_H
