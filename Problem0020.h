//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0020_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0020_H

#include <string>
#include <stack>

using namespace std;

class Problem0020 {
public:
    bool isValid(const string &s) {
        char couple[256];
        couple[')'] = '(';
        couple[']'] = '[';
        couple['}'] = '{';
        stack<char> stk;
        for (const char &ch: s) {
            if (ch == ')' || ch == ']' || ch == '}') {
                if (!stk.empty() && stk.top() == couple[ch]) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.emplace(ch);
            }
        }
        return stk.empty();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0020_H
