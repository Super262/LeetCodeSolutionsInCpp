//
// Created by Fengwei Zhang on 5/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0439_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0439_H

#include <string>
#include <stack>

using namespace std;

class Solution {
    // 类似括号匹配问题，根据题意，从后向前遍历expr、跳过":"，变量入栈；
    // 在第i位遇到"?"时，取出栈内最近2个变量、结合第(i-1)位的变量，计算三元表达式的值，将结果入栈；持续操作，直到栈内只有1个元素
public:
    string parseTernary(const string &expr) {
        stack<char> stk;
        for (auto i = (int) expr.size() - 1; i >= 0; --i) {
            if (expr[i] == ':') {
                continue;
            }
            if (expr[i] != '?') {
                stk.emplace(expr[i]);
                continue;
            }
            auto a = stk.top();
            stk.pop();
            auto b = stk.top();
            stk.pop();
            auto c = expr[i - 1];
            --i;
            if (c == 'T') {
                stk.emplace(a);
            } else {
                stk.emplace(b);
            }
        }
        return string(1, stk.top());
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0439_H
