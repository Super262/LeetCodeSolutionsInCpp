//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0459_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0459_H

#include <string>

using namespace std;

class Solution {
    // 利用KMP算法的性质：(i - fail[i] + 1)是字符串s[0:i]的最小周期；最小周期x是所有周期的公约数
    // 若最小周期x不能整除n，则所有周期都不能整除n
public:
    bool repeatedSubstringPattern(const string &s) {
        const auto n = (int) s.size();
        int fail[n];
        int l = 0;
        int r = 1;
        fail[l] = 0;
        while (r < n) {
            if (s[l] == s[r]) {
                ++l;
                fail[r] = l;
                ++r;
            } else if (l) {
                l = fail[l - 1];
            } else {
                fail[r] = 0;
                ++r;
            }
        }
        auto t = (n - 1) - fail[n - 1] + 1;
        return t < n && n % t == 0;  // 周期不能等于原串：t < n
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0459_H
