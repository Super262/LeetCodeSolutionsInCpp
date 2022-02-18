//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0674_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0674_H

#include <vector>

using namespace std;

class Solution {
    // 双指针遍历所有上升子序列，记录最大值
public:
    int findLengthOfLCIS(const vector<int> &nums) {
        int res = 1;
        for (int l = 0, r = 0; r < (int) nums.size(); ++r) {
            while (l < r && nums[r] <= nums[r - 1]) {
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0674_H
