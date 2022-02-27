//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0770_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0770_H

#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> basicCalculatorIV(const string &expr, vector<string> &vars, vector<int> &vals) {
        unordered_map<string, int> values;  // 自变量的值
        stack<vector<Item>> exprs; // 参与运算的表达式（Item序列）
        stack<char> ops;  // 运算符
        for (int i = 0; i < vars.size(); ++i) {
            values[vars[i]] = vals[i];
        }
        auto t = calculate(expr, values, exprs, ops);
        vector<string> res;
        res.reserve(t.size());
        for (const auto &item: t) {
            res.emplace_back(item.toString());
        }
        return res;
    }

private:
    struct Item {
        int c;  // 当前项的系数
        multiset<string> vars;  // 自变量，可能有重复值

        Item(int c, const multiset<string> &vars) {
            this->c = c;
            this->vars = vars;
        }

        bool operator<(const Item &t) const {
            if (vars.size() != t.vars.size()) {  // 次数高的靠前
                return vars.size() > t.vars.size();
            }
            return vars < t.vars;  // 字典需小的靠前
        }

        bool operator==(const Item &t) const {  // 注意：这里只是判断自变量是否相同，用于合并同类项
            return vars == t.vars;
        }

        string toString() const {
            auto res = to_string(c);
            for (const auto &v: vars) {
                res += "*";
                res += v;
            }
            return res;
        }
    };

    vector<Item> calculate(const string &str,
                           unordered_map<string, int> &values,
                           stack<vector<Item>> &exprs,
                           stack<char> &ops) {
        unordered_map<char, int> pr{{'+', 1},
                                    {'-', 1},
                                    {'*', 2}};  // 运算优先级
        for (int i = 0; i < (int) str.size(); ++i) {
            if (str[i] == ' ') {
                continue;
            }
            if (str[i] >= 'a' && str[i] <= 'z' || isdigit(str[i])) {
                vector<Item> expr;
                if (str[i] >= 'a' && str[i] <= 'z') {
                    string var;
                    auto j = i;
                    while (j < str.size() && str[j] >= 'a' && str[j] <= 'z') {
                        var += str[j];
                        ++j;
                    }
                    i = j - 1;
                    if (values.count(var)) {
                        if (values[var]) {
                            expr.push_back({values[var], {}});
                        }
                    } else {
                        expr.push_back({1, {var}});
                    }
                } else {
                    int x = 0;
                    auto j = i;
                    while (j < str.size() && isdigit(str[j])) {
                        x = x * 10 + (str[j] - '0');
                        ++j;
                    }
                    i = j - 1;
                    if (x) {
                        expr.push_back({x, {}});
                    }
                }
                exprs.emplace(expr);
            } else if (str[i] == '(') {
                ops.emplace(str[i]);
            } else if (str[i] == ')') {
                while (ops.top() != '(') {
                    eval(values, exprs, ops);
                }
                ops.pop();
            } else {
                while (!ops.empty() && ops.top() != '(' && pr[ops.top()] >= pr[str[i]]) {
                    eval(values, exprs, ops);
                }
                ops.emplace(str[i]);
            }
        }
        while (!ops.empty()) {
            eval(values, exprs, ops);
        }
        return exprs.top();
    }

    void eval(unordered_map<string, int> &values,
              stack<vector<Item>> &exprs,
              stack<char> &ops) {
        auto b = exprs.top();
        exprs.pop();
        auto a = exprs.top();
        exprs.pop();
        auto op = ops.top();
        ops.pop();
        vector<Item> c;
        if (op == '+') {
            c = exprAdd(a, b, true);
        } else if (op == '-') {
            c = exprAdd(a, b, false);
        } else {
            c = exprMultiply(a, b);
        }
        exprs.emplace(c);
    }

    // 多项式相加，合并同类项：a+b或a-b
    vector<Item> exprAdd(const vector<Item> &a, const vector<Item> &b, bool sign) {  // sign：+b或-b
        vector<Item> res;
        int i = 0;
        int j = 0;
        while (i < (int) a.size() && j < (int) b.size()) {  // 二路归并
            if (a[i] == b[j]) {  // 是同类项
                auto tc = a[i].c + (sign ? 1 : -1) * b[j].c;
                if (tc) {
                    Item t(tc, a[i].vars);
                    res.emplace_back(t);
                }
                ++i;
                ++j;
            } else if (a[i] < b[j]) {
                res.emplace_back(a[i]);
                ++i;
            } else {
                auto tc = (sign ? 1 : -1) * b[j].c;
                Item t(tc, b[j].vars);
                res.emplace_back(t);
                ++j;
            }
        }
        while (i < (int) a.size()) {
            res.emplace_back(a[i]);
            ++i;
        }
        while (j < (int) b.size()) {
            auto tc = (sign ? 1 : -1) * b[j].c;
            Item t(tc, b[j].vars);
            res.emplace_back(t);
            ++j;
        }
        return res;
    }

    vector<Item> exprMultiply(const vector<Item> &a, const vector<Item> &b) {
        vector<Item> res;
        for (const auto &x: a) {  // 逐项配对
            vector<Item> expr;
            for (const auto &y: b) {
                Item t(x.c * y.c, x.vars);
                for (const auto &v: y.vars) {
                    t.vars.insert(v);
                }
                expr.emplace_back(t);
            }
            res = exprAdd(res, expr, true);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0770_H
