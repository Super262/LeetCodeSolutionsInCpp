//
// Created by Fengwei Zhang on 4/6/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0856_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0856_H

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(const string &s) {
        stack<int> stk;
        stk.emplace(0);
        for (const auto &ch: s) {
            if (ch == '(') {
                stk.emplace(0);
            } else {
                int t = stk.top();
                stk.pop();
                if (!t) {
                    t = 1;
                } else {
                    t *= 2;
                }
                stk.top() += t;
            }
        }
        return stk.top();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0856_H
