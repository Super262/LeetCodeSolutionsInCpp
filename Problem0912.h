//
// Created by Fengwei Zhang on 4/12/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0912_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0912_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        const auto n = (int) nums.size();
        quick_sort(nums, 0, n - 1);
        return nums;
    }

private:
    void quick_sort(vector<int> &nums, int st, int ed) {
        if (st >= ed) {
            return;
        }
        auto l = st - 1;
        auto r = ed + 1;
        auto p = nums[l + (r - l) / 2];
        while (l < r) {
            while (nums[++l] < p);
            while (nums[--r] > p);
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        quick_sort(nums, st, r);
        quick_sort(nums, r + 1, ed);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0912_H
