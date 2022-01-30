//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0027_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0027_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, const int &val) {
        int k = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (nums[i] == val) {
                continue;
            }
            nums[k] = nums[i];
            ++k;
        }
        return k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0027_H
