//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0860_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0860_H

#include <vector>

using namespace std;

class Solution {
    // 1张十元可以被2张五元替换
public:
    bool lemonadeChange(const vector<int> &bills) {
        int five = 0;
        int ten = 0;
        for (const auto &x: bills) {
            if (x == 5) {
                ++five;
                continue;
            }
            if (x == 10) {
                if (!five) {
                    return false;
                }
                --five;
                ++ten;
                continue;
            }
            if (ten && five) {
                --ten;
                --five;
                continue;
            }
            if (five < 3) {
                return false;
            }
            five -= 3;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0860_H
