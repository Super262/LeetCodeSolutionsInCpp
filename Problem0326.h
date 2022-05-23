//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0326_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0326_H

#include <cmath>

using namespace std;

class Solution {
    // 巧妙技巧：32位整数中最大的3^x是3^19，若n可以整除3^19，返回true
public:
    bool isPowerOfThree(const int &n) {
        return n > 0 && ((int) pow(3, 19)) % n == 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0326_H
