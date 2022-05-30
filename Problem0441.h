//
// Created by Fengwei Zhang on 12/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0441_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0441_H

#include <cmath>

using namespace std;

class Solution {
    // 等差数列的和：x*(x+1)/2=n，求解x；利用二元一次方程的求根公式计算出解
public:
    int arrangeCoins(int n) {
        return (int) ((sqrt(1ll + 8ll * n) - 1) / 2);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0441_H
