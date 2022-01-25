//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0507_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0507_H

class Solution {
public:
    bool checkPerfectNumber(const int num) {
        if (num == 1) {
            return false;
        }
        int sum = 1;
        for (int f = 2; f <= num / f; ++f) {
            if (num % f) {
                continue;
            }
            if (f == num / f) {
                continue;
            }
            sum += f + num / f;
        }
        return sum == num;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0507_H
