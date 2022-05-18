//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0280_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0280_H

#include <vector>

using namespace std;

class Solution {
    // 交换元素到满足题意的位置
    // 细节：注意区分奇数位置和偶数位置
public:
    void wiggleSort(vector<int> &nums) {
        for (int i = 1; i < (int) nums.size(); ++i) {
            if ((i % 2 != 0 && nums[i - 1] > nums[i]) || (i % 2 == 0 && nums[i - 1] < nums[i])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0280_H
