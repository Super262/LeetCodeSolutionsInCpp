//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0026_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0026_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int k = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            nums[k] = nums[i];
            ++k;
        }
        return k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0026_H
