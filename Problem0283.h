//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0283_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0283_H

#include <vector>

using namespace std;

class Solution {
    // 将所有非零数字移到数组头部，在数组尾部填充零
public:
    void moveZeroes(vector<int> &nums) {
        int k = 0;
        for (int x: nums) {
            if (x == 0) {
                continue;
            }
            nums[k++] = x;
        }
        while (k < nums.size()) {
            nums[k++] = 0;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0283_H
