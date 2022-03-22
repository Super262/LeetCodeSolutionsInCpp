//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0150_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0150_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(const vector<string> &tokens) {
        stack<int> stk;
        for (const auto &s: tokens) {
            if (s == "+") {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();
                stk.emplace(a + b);
                continue;
            }
            if (s == "-") {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();
                stk.emplace(a - b);
                continue;
            }
            if (s == "*") {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();
                stk.emplace(a * b);
                continue;
            }
            if (s == "/") {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();
                stk.emplace(a / b);
                continue;
            }
            stk.emplace(stoi(s));
        }
        return stk.top();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0150_H
