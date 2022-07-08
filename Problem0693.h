//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0693_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0693_H

class Solution {
    // 若对于任意0<i<n，二进制序列s满足s[i-1]!=s[i]，返回true；否则返回false
public:
    bool hasAlternatingBits(int n) {
        while (n) {
            auto a = n % 2;
            n /= 2;
            auto b = n % 2;
            if (a == b) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0693_H
