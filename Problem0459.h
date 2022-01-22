//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0459_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0459_H

#include <string>

using namespace std;

class Solution {
    // 利用KMP算法的性质：(n - next[n])是字符串的最小周期；最小周期x是所有周期的公约数；
    // 若最小周期x不能整除n，则所有周期都不能整除n。
public:
    bool repeatedSubstringPattern(const string &s) {
        const auto n = (int) s.size();
        int next_start[n];
        next_start[0] = 0;
        int l = 0, r = 1;
        while (r < n) {
            if (s[l] == s[r]) {
                ++l;
                next_start[r] = l;
                ++r;
            } else if (l) {
                l = next_start[l - 1];
            } else {
                next_start[r] = 0;
                ++r;
            }
        }
        auto t = (n - 1) - next_start[n - 1] + 1;
        return t < n && n % t == 0;  // 周期不能等于原串：t < n
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0459_H
