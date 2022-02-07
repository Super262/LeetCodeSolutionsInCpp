//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0190_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0190_H

#include <algorithm>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;
            result += (n >> i) & 1;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0190_H
