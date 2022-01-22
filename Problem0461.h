//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0461_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0461_H

class Solution {
    // 枚举x、y各位并比较
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x || y) {
            res += (x & 1) != (y & 1);
            x >>= 1;
            y >>= 1;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0461_H
