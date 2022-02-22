//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0713_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0713_H

#include <vector>

using namespace std;

class Solution {
    // nums中只包含正数，可用双指针
public:
    int numSubarrayProductLessThanK(const vector<int> &nums, int k) {
        int res = 0;
        int temp = 1;
        for (int l = 0, r = 0; r < (int) nums.size(); ++r) {
            temp *= nums[r];
            while (l <= r && temp >= k) {
                temp /= nums[l];
                ++l;
            }
            res += r - l + 1;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0713_H
