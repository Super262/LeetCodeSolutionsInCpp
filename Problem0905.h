//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0905_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0905_H

#include <vector>

using namespace std;

class Solution {
    // 参考快速排序，交换奇偶
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int l = 0;
        auto r = (int) nums.size() - 1;
        while (l < r) {
            while (l < r && nums[l] % 2 == 0) {
                ++l;
            }
            while (l < r && nums[r] % 2) {
                --r;
            }
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        return nums;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0905_H
