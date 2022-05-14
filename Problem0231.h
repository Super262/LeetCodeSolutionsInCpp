//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0231_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0231_H

class Solution {
    // a>0，若a=2^x，则lowBit(a)=a
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0231_H
