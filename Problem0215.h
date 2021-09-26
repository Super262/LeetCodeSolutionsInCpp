//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0215_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0215_H

#include <vector>

using namespace std;

class Problem0215 {
private:
    void helper(vector<int> &nums, const int start, const int end, const int k) {
        if (start >= end) {
            return;
        }
        auto pivot = nums[start + (end - start) / 2];
        auto left = start - 1;
        auto right = end + 1;
        while (left < right) {
            while (nums[++left] > pivot);
            while (nums[--right] < pivot);
            if (left < right) {
                swap(nums[left], nums[right]);
            }
        }
        if (right - start + 1 >= k) {
            helper(nums, start, right, k);
        } else {
            helper(nums, right + 1, end, k - (right - start + 1));
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        helper(nums, 0, (int) nums.size() - 1, k);
        return nums[k - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0215_H
