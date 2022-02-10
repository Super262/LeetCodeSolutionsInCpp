//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0647_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0647_H

#include <string>

using namespace std;

class Solution {
    // 经典算法，必须掌握：数据范围小，暴力枚举
public:
    int countSubstrings(const string &s) {
        int res = 0;
        for (int i = 0; i < (int) s.size(); ++i) {
            for (int l = i, r = i; l >= 0 && r < (int) s.size(); --l, ++r) {  // 奇数长度
                if (s[l] != s[r]) {
                    break;
                }
                ++res;
            }
            for (int l = i, r = i + 1; l >= 0 && r < (int) s.size(); --l, ++r) {  // 偶数长度
                if (s[l] != s[r]) {
                    break;
                }
                ++res;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0647_H
