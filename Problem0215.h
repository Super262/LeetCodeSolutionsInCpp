//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0215_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0215_H

#include <vector>

using namespace std;

class Solution {
    // The same solution for problem 912 cannot be applied here 
    // due to exceeding time limitations.
public:
    int findKthLargest(vector<int> &nums, int k) {
        myQuickSelect(nums, 0, (int) nums.size() - 1, k);
        return nums[k - 1];
    }

private:
    void myQuickSelect(vector<int> &nums, int st, int ed, int k) {
        if (st >= ed) {
            return;
        }
        auto pivot = nums[st + (ed - st) / 2];
        auto l = st - 1;
        auto r = ed + 1;
        while (l < r) {
            ++l;
            while (nums[l] > pivot) {
                ++l;
            }
            --r;
            while (nums[r] < pivot) {
                --r;
            }
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        if (r - st + 1 >= k) {
            myQuickSelect(nums, st, r, k);
        } else {
            myQuickSelect(nums, r + 1, ed, k - (r - st + 1));
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0215_H
