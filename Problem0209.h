//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0209_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0209_H

#include <vector>

using namespace std;

class Solution {
    // 牢记双指针算法的正确性（单调性）证明！
public:
    int minSubArrayLen(const int &target, const vector<int> &nums) {
        const int n = (int) nums.size();
        int result = n + 1;
        for (int l = 0, r = 0, temp = 0; r < n; ++r) {
            temp += nums[r];
            while (l <= r && temp >= target) {
                result = min(result, r - l + 1);
                temp -= nums[l++];
            }
        }
        if (result == n + 1) {
            result = 0;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0209_H
