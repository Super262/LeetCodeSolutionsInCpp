//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1004_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1004_H

#include <vector>

using namespace std;

class Solution {
    // 双指针：找到最长的子数组，最多包含k个0
public:
    int longestOnes(const vector<int> &nums, int k) {
        int ans = 0;
        for (int l = 0, r = 0, zero_cnt = 0; r < (int) nums.size(); ++r) {
            if (!nums[r]) {
                ++zero_cnt;
            }
            while (l <= r && zero_cnt > k) {
                if (!nums[l]) {
                    --zero_cnt;
                }
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1004_H
