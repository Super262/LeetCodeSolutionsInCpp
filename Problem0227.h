//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0227_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0227_H

#include <stack>
#include <cctype>

using namespace std;

class Problem0227 {
private:
    void evaluate(stack<int> &nums, stack<char> &ops) {
        auto b = nums.top();
        nums.pop();
        auto a = nums.top();
        nums.pop();
        auto op = ops.top();
        ops.pop();
        if (op == '*') {
            nums.emplace(a * b);
        }
        if (op == '/') {
            nums.emplace(a / b);
        }
        if (op == '+') {
            nums.emplace(a + b);
        }
        if (op == '-') {
            nums.emplace(a - b);
        }
    }

    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        int priority[256];
        priority['+'] = priority['-'] = 1;
        priority['*'] = priority['/'] = 2;
        for (int i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            if (ch == ' ') {
                continue;
            }
            if (isdigit(ch)) {
                int x = 0;
                int j = i;
                while (j < s.size() && isdigit(s[j])) {
                    x = x * 10 + (s[j] - '0');
                    ++j;
                }
                nums.emplace(x);
                i = j - 1;
            } else {
                while (!ops.empty() && priority[ops.top()] >= priority[ch]) {
                    evaluate(nums, ops);
                }
                ops.emplace(ch);
            }
        }
        while (!ops.empty()) {
            evaluate(nums, ops);
        }
        return nums.top();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0227_H
