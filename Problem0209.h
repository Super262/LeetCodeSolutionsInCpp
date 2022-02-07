//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0209_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0209_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵：https://www.acwing.com/solution/content/268/
    // 牢记双指针算法的正确性（单调性）证明！
public:
    int minSubArrayLen(const int target, const vector<int> &nums) {
        const auto n = (int) nums.size();
        auto res = n + 1;
        for (int l = 0, r = 0, temp = 0; r < n; ++r) {
            temp += nums[r];
            while (l <= r && temp >= target) {
                temp -= nums[l];
                ++l;
            }
            if (l > 0) { // [l-1,r]满足题意
                res = min(res, r - l + 2);
            }
        }
        if (res == n + 1) {
            return 0;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0209_H
