//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0507_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0507_H

class Solution {
    // 特殊情况："1"不是完美数；其它情况：试除法求出num的所有质因子，若质因子的和sum等于num，num是完美数
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
