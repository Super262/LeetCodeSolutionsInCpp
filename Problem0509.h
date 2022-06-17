//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0509_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0509_H

class Solution {
    // 终极优化：矩阵快速幂
public:
    int fib(int n) {
        if (!n) {
            return 0;
        }
        int f0 = 0;
        int f1 = 1;
        while (n > 1) {
            auto f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
            --n;
        }
        return f1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0509_H
