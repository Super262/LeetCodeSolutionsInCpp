//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0055_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0055_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0055 {
private:
    bool canJump(vector<int> &nums) {
        for (int i = 0, j = 0; i < (int) nums.size(); ++i) {
            if (j < i) {
                return false;
            }
            j = max(j, i + nums[i]);
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0055_H
