//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0215_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0215_H

#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        helper(nums, 0, (int) nums.size() - 1, k);
        return nums[k - 1];
    }

private:
    void helper(vector<int> &nums, const int st, const int ed, const int k) {
        if (st >= ed) {
            return;
        }
        auto pivot = nums[st + (ed - st) / 2];
        auto l = st - 1;
        auto r = ed + 1;
        while (l < r) {
            while (nums[++l] > pivot);
            while (nums[--r] < pivot);
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        if (r - st + 1 >= k) {
            helper(nums, st, r, k);
        } else {
            helper(nums, r + 1, ed, k - (r - st + 1));
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0215_H
