//
// Created by Fengwei Zhang on 4/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0961_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0961_H

#include <vector>

using namespace std;

class Solution {
    // 抽屉原理：将这个长度为2*n的数组看作n个长度为2的抽屉；设nums中出现n次的数是t
    // 因此，每个抽屉可能包含2个t，此时有些抽屉不含t；或者每个抽屉含1个t
public:
    int repeatedNTimes(const vector<int> &nums) {
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] == nums[i + 1]) {  // 存在含有2个t的抽屉
                return nums[i];
            }
        }
        // 每个抽屉含1个t
        if (nums[0] == nums[2] || nums[0] == nums[3]) {
            return nums[0];
        }
        return nums[1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0961_H
