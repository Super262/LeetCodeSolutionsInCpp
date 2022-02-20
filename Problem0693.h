//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0693_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0693_H

class Solution {
public:
    bool hasAlternatingBits(int n) {
        for (int i = 1; (1ll << i) <= n; ++i) {
            auto a = (n >> (i - 1)) & 1;
            auto b = (n >> i) & 1;
            if (a == b) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0693_H
