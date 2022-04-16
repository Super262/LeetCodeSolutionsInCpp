//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0946_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0946_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 直接模拟：若栈顶等于popped[i]，出栈，i后移
public:
    bool validateStackSequences(const vector<int> &pushed, const vector<int> &popped) {
        stack<int> stk;
        int i = 0;
        for (const auto &x: pushed) {
            stk.emplace(x);
            while (!stk.empty() && stk.top() == popped[i]) {
                ++i;
                stk.pop();
            }
        }
        return i == (int) popped.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0946_H
