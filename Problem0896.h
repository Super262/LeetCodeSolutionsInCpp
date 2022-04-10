//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0896_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0896_H

#include <vector>

using namespace std;

class Solution {
    // 排除"相等"情况的影响，只判断严格递增或递减
public:
    bool isMonotonic(const vector<int> &nums) {
        bool inc = true;
        bool dec = true;
        for (int i = 1; i < (int) nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                dec = false;
                continue;
            }
            if (nums[i - 1] > nums[i]) {
                inc = false;
            }
        }
        return inc || dec;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0896_H
