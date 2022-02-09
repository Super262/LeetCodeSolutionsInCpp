//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0640_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0640_H

#include <string>

using namespace std;

class Solution {
public:
    string solveEquation(const string &equation) {
        auto div = equation.find_first_of('=');
        auto le = equation.substr(0, div);
        auto re = equation.substr(div + 1);
        auto lc = parse(le);
        auto rc = parse(re);
        auto a = lc.first - rc.first;  // 化简后x的系数在左
        auto b = rc.second - lc.second;  // 常数项在右
        if (!a) {
            if (!b) {
                return "Infinite solutions";
            }
            return "No solution";
        }
        return "x=" + to_string(b / a);
    }

private:
    pair<int, int> parse(string &s) {  // 返回x系数和常数项
        if (s[0] != '+' && s[0] != '-') {
            s = "+" + s;
        }
        const auto n = (int) s.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {  // 保持i指向符号位
            auto j = i + 1;
            int c = 0;
            while (j < n && isdigit(s[j])) {
                c = c * 10 + (s[j] - '0');
                ++j;
            }
            if (j == i + 1) {  // 整数为1
                c = 1;
            }
            if (j < n && s[j] == 'x') { // x的系数
                a += s[i] == '-' ? -c : c;
                i = j;
            } else {  // 常数项
                b += s[i] == '-' ? -c : c;
                i = j - 1;
            }
        }
        return {a, b};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0640_H
