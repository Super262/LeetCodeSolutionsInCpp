//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0150_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0150_H

#include <vector>
#include <stack>

using namespace std;

class Problem0150 {
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
            } else if (s == "-") {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();
                stk.emplace(a - b);
            } else if (s == "*") {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();
                stk.emplace(a * b);
            } else if (s == "/") {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();
                stk.emplace(a / b);
            } else {
                stk.emplace(stoi(s));
            }
        }
        return stk.top();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0150_H
