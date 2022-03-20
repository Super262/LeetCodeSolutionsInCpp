//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0371_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0371_H

class Solution {
    // 1. "不进位加法"：a ^ b
    // 2. 填充进位：避免使用"+"，实现 (a ^ b) + ((a & b) << 1)
public:
    int getSum(int a, int b) {
        while (a) {
            auto sum = a ^ b;
            auto carry = (unsigned int) (a & b) << 1;
            a = (int) carry;
            b = sum;
        }
        return b;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0371_H
