//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0343_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0343_H

class Solution {
    // 尽可能分成3和2，最多只能有2个2
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int p = 1;
        while (n >= 5) {
            n -= 3;
            p *= 3;
        }
        return p * n;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0343_H
