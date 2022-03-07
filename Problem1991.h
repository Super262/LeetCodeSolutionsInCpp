//
// Created by Fengwei Zhang on 3/6/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1991_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1991_H

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int> &nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0, s = 0; i < nums.size(); ++i) {
            if (2 * s == sum - nums[i]) {
                return i;
            }
            s += nums[i];
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1991_H
