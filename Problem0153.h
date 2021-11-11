//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0153_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0153_H

#include <vector>

using namespace std;

class Problem0153 {
public:
    int findMin(const vector<int> &nums) {
        int l = 0;
        int r = (int) nums.size() - 1;
        if (nums[r] > nums[l]) {
            return nums[l];
        }
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0153_H
