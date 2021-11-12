//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0169_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0169_H

#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(const vector<int> &nums) {  // 直接背诵
        int x;
        int r = 0;
        for (const auto &num: nums) {
            if (r == 0) {
                x = num;
                r = 1;
            } else if (x == num) {
                ++r;
            } else {
                --r;
            }
        }
        return x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0169_H
