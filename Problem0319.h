//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0319_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0319_H

#include <cmath>

using namespace std;

class Solution {
    // 灯泡i被按下的次数：i的约数个数
    // 数学性质：完全平方数的约数个数是奇数（充要条件
    // https://www.acwing.com/solution/content/346/
public:
    int bulbSwitch(const int &n) {
        return (int) sqrt(n);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0319_H
