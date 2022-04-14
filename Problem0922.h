//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0922_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0922_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2) {
            while (i < nums.size() && nums[i] % 2 == 0) {
                i += 2;
            }
            while (j < nums.size() && nums[j] % 2) {
                j += 2;
            }
            if (i < nums.size() && j < nums.size()) {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0922_H
