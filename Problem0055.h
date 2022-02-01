//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0055_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0055_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool canJump(const vector<int> &nums) {
        for (int l = 0, r = 0; l < (int) nums.size(); ++l) {
            if (r < l) {
                return false;
            }
            r = max(r, l + nums[l]);
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0055_H
