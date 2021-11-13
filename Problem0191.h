//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0191_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0191_H

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            n -= lowBit(n);
            ++result;
        }
        return result;
    }

private:
    uint32_t lowBit(const uint32_t &x) {
        return x & -x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0191_H
