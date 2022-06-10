//
// Created by Fengwei Zhang on 6/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0487_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0487_H

#include <vector>

using namespace std;

class Solution {
    // 双指针，维护最多包含1个"0"的滑动窗口[l:r]，使区间长度r-l+1最大
    // 基础做法：用zeroes_cnt记录"0"的个数，当"0"的个数超过1时，左移l，并更新zeroes_cnt
    // 优化：last_zero记录上个"0"的位置，新的"0"出现时，设置l为last_zero+1，更新last_zero
public:
    int findMaxConsecutiveOnes(const vector<int> &nums) {
        int ans = 1;
        for (int l = 0, r = 0, last_zero = -1; r < (int) nums.size(); ++r) {
            if (!nums[r]) {
                l = last_zero + 1;
                last_zero = r;
            }
            ans = max(r - l + 1, ans);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0487_H
