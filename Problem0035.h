//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0035_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0035_H

#include <vector>

using namespace std;

class Problem0035 {
public:
    int searchInsert(const vector<int> &nums, const int &target) {
        int left = 0;
        int right = (int) nums.size();
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0035_H
