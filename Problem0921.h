
//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0921_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0921_H

#include <string>

using namespace std;

class Solution {
    // 合法的括号序列："("和")"的数量相同；任意前缀，"("的数量不少于")"的数量
public:
    int minAddToMakeValid(const string &s) {
        int l = 0;  // 所需左括号的数量
        int r = 0;  // 所需右括号的数量
        for (const auto &ch: s) {
            if (ch == '(') {
                ++l;
                continue;
            }
            if (l) {
                --l;
            } else {
                ++r;
            }
        }
        return l + r;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0921_H
