//
// Created by Fengwei Zhang on 2/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0704_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0704_H

#include <vector>

using namespace std;

class Solution {
public:
    int search(const vector<int> &nums, const int t) {
        int l = 0;
        int r = (int) nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[r] == t ? r : -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0704_H
