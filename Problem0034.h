//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0034_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0034_H

#include <vector>

using namespace std;

class Problem0034 {
public:
    vector<int> searchRange(const vector<int> &nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        int l = 0, r = (int) nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[r] != target) {
            return {-1, -1};
        }
        vector<int> result(2, r);
        l = 0, r = (int) nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l + 1) / 2;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        result[1] = l;
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0034_H
