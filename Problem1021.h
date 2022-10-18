//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1021_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1021_H

#include <string>

using namespace std;

class Problem1021 {
    // 通过记录左括号的数量，我们可以确定最外层括号序列的位置
public:
    string removeOuterParentheses(const string &s) {
        string ans;
        for (int l = 0, r = 0, left_cnt = 0; r < (int) s.size(); ++r) {
            if (s[r] == '(') {
                ++left_cnt;
                continue;
            }
            --left_cnt;
            if (!left_cnt) {
                ans += s.substr(l + 1, r - l - 1);  // 去掉最外层括号
                l = r + 1;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1021_H
