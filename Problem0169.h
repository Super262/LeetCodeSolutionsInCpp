//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0169_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0169_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵
public:
    int majorityElement(const vector<int> &nums) {
        int x;
        int r = 0;
        for (const auto &num: nums) {
            if (r == 0) {
                x = num;
                r = 1;
                continue;
            }
            if (x == num) {
                ++r;
                continue;
            }
            --r;
        }
        return x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0169_H
