//
// Created by Fengwei Zhang on 4/12/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0912_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0912_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        myQuickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void myQuickSort(vector<int>& nums, size_t st, size_t ed) {
        if (st >= ed) {
            return; // No need to sort
        }

        auto p = myPartition(nums, st, ed); // Get pivot index
        if (p > 0) { // Ensure no underflow when subtracting 1
            myQuickSort(nums, st, p - 1); // Recursively sort left part
        }
        myQuickSort(nums, p + 1, ed);     // Recursively sort right part
    }

    size_t myPartition(vector<int>& nums, size_t st, size_t ed) {
        auto p = st + (ed - st) / 2; // Choose middle as pivot
        auto pivot = nums[p];          // Store the pivot value
        auto l = st + 1;
        auto r = ed;

        swap(nums[p], nums[st]); // Move pivot to start

        while (l <= r) {
            while (l <= r && nums[l] <= pivot) {
                ++l;
            }
            while (l <= r && nums[r] >= pivot) {
                --r;
            }
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }

        swap(nums[st], nums[r]); // Place pivot in its correct position
        return r; // Return the partition index
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0912_H
