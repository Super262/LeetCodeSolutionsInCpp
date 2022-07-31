//
// Created by Fengwei Zhang on 7/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0772_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0772_H

#include <string>
#include <stack>
#include <vector>

using namespace std;

class Problem0772 {
    // 我们将输入的字符串s转换为逆波兰表达式tokens，再遍历tokens得出答案
    // 我们引入变量need_zero处理负数；若出现负数，设置need_zero=true；初始时，在s尾部加入空格，用于指示终点
public:
    int calculate(string s) {
        vector<Token> tokens;
        stack<char> ops;
        s += ' ';
        int num = -1;
        bool need_zero = true;
        for (const auto &ch: s) {
            if (isdigit(ch)) {
                if (num == -1) {
                    num = 0;
                }
                num = num * 10 + (ch - '0');
                need_zero = false;
                continue;
            }
            if (num != -1) {
                tokens.push_back({num, '\0', true});
                num = -1;
            }
            if (ch == ' ') {
                continue;
            }
            if (ch == '(') {
                ops.emplace(ch);
                need_zero = true;
                continue;
            }
            if (ch == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    tokens.push_back({-1, ops.top(), false});
                    ops.pop();
                }
                ops.pop();
                need_zero = false;
                continue;
            }
            if ((ch == '+' || ch == '-') && need_zero) {
                tokens.push_back({0, '\0', true});
            }
            auto rank = getRank(ch);
            while (!ops.empty() && getRank(ops.top()) >= rank) {
                tokens.push_back({-1, ops.top(), false});
                ops.pop();
            }
            ops.emplace(ch);
            need_zero = true;
        }
        while (!ops.empty()) {
            tokens.push_back({-1, ops.top(), false});
            ops.pop();
        }
        return evalRPN(tokens);
    }

private:
    struct Token {
        int number;
        char op;
        bool is_num;
    };

    int evalRPN(const vector<Token> &tokens) {
        stack<long> stk;
        for (const auto &t: tokens) {
            if (t.is_num) {
                stk.emplace(t.number);
            } else {
                auto y = stk.top();
                stk.pop();
                auto x = stk.top();
                stk.pop();
                stk.emplace(calc(x, y, t.op));
            }
        }
        return (int) stk.top();
    }

    long calc(long x, long y, char op) {
        if (op == '+') {
            return x + y;
        }
        if (op == '-') {
            return x - y;
        }
        if (op == '*') {
            return x * y;
        }
        return x / y;
    }

    int getRank(char ch) {
        if (ch == '-' || ch == '+') {
            return 1;
        }
        if (ch == '*' || ch == '/') {
            return 2;
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0772_H
