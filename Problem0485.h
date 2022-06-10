//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0485_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0485_H

#include <vector>

using namespace std;

class Solution {
    // 双指针，找到全为"1"的nums[i:j]，使得j-i最大
public:
    int findMaxConsecutiveOnes(const vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (!nums[i]) {
                continue;
            }
            auto j = i;
            while (j < (int) nums.size() && nums[j] == 1) {
                ++j;
            }
            ans = max(j - i, ans);
            i = j - 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0485_H
