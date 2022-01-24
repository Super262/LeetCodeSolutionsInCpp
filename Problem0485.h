//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0485_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0485_H

#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(const vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                continue;
            }
            auto j = i;
            while (j < nums.size() && nums[j] == 1) {
                ++j;
            }
            res = max(j - i, res);
            i = j - 1;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0485_H
