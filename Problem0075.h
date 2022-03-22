//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0075_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0075_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵
public:
    void sortColors(vector<int> &nums) {
        int i = 0, j = 0, k = (int) nums.size() - 1;
        while (j <= k) {
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                ++i;
                ++j;
            } else if (nums[j] == 1) {
                ++j;
            } else {
                swap(nums[j], nums[k]);
                --k;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0075_H
