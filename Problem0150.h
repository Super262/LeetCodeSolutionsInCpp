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
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                doOperation(s, stk);
                continue;
            }
            stk.emplace(stoi(s));
        }
        return stk.top();
    }

private:
    void doOperation(const string &op, stack<int> &stk) {
        auto b = stk.top();
        stk.pop();
        auto a = stk.top();
        stk.pop();
        if (op == "+") {
            stk.emplace(a + b);
        } else if (op == "-") {
            stk.emplace(a - b);
        } else if (op == "*") {
            stk.emplace(a * b);
        } else {
            stk.emplace(a / b);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0150_H
