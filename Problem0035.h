//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0035_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0035_H

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(const vector<int> &nums, const int &target) {
        int left = 0;
        int right = (int) nums.size() - 1;
        while (left < right) {
            auto mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if (nums[right] < target) {
            return right + 1;
        }
        return right;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0035_H
