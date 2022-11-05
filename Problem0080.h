//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0080_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0080_H

#include <vector>

using namespace std;

class Problem0080 {
    // 经典算法，直接背诵
public:
    int removeDuplicates(vector<int> &nums) {
        int k = 0;
        for (auto x: nums) {
            if (k < 2 || nums[k - 1] != x || nums[k - 2] != x) {
                nums[k++] = x;
            }
        }
        return k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0080_H
