//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1003_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1003_H

#include <string>

using namespace std;

class Solution {
    // 类似"合法的括号序列"问题，直接利用栈来模拟
public:
    bool isValid(const string &s) {
        string stk;
        for (const auto &ch: s) {
            stk.push_back(ch);
            if (stk.size() >= 3 && stk.substr(stk.size() - 3) == "abc") {
                for (int j = 0; j < 3; ++j) {
                    stk.pop_back();
                }
            }
        }
        return stk.empty();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1003_H
