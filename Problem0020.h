//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0020_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0020_H

#include <string>
#include <stack>

using namespace std;

class Problem0020 {
private:
    bool isValid(const string &s) {
        stack<char> temp;
        for (char c: s) {
            switch (c) {
                case ')': {
                    if (!temp.empty() && temp.top() == '(') {
                        temp.pop();
                    } else {
                        return false;
                    }
                    break;
                }
                case ']': {
                    if (!temp.empty() && temp.top() == '[') {
                        temp.pop();
                    } else {
                        return false;
                    }
                    break;
                }
                case '}': {
                    if (!temp.empty() && temp.top() == '{') {
                        temp.pop();
                    } else {
                        return false;
                    }
                    break;
                }
                default: {
                    temp.emplace(c);
                    break;
                }
            }
        }
        return temp.empty();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0020_H
