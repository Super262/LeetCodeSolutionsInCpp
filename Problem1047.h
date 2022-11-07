//
// Created by Fengwei Zhang on 11/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1047_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1047_H

#include <string>
#include <stack>

using namespace std;

class Problem1047 {
public:
    string removeDuplicates(const string &s) {
        stack<char> stk;
        for (const auto &ch: s) {
            if (stk.empty() || stk.top() != ch) {
                stk.emplace(ch);
                continue;
            }
            while (!stk.empty() && stk.top() == ch) {
                stk.pop();
            }
        }
        string ans;
        ans.reserve(stk.size());
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1047_H
