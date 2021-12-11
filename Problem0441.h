//
// Created by Fengwei Zhang on 12/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0441_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0441_H

#include <cmath>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return (int) ((sqrt(1ll + 8ll * n) - 1) / 2);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0441_H
