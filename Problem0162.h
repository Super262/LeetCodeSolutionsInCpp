//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0162_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0162_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，必须掌握
    // https://www.acwing.com/solution/content/258/
    // 题目要求返回任意一个峰值，所以并不是连续的二分
public:
    int findPeakElement(const vector<int> &nums) {
        int l = 0;
        int r = (int) nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] <= nums[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0162_H
