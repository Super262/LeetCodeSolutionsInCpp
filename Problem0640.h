//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0640_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0640_H

#include <string>

using namespace std;

class Solution {
    // 分别化简"="左侧式子le和右侧式子re为最简式ax+b和cx+d，再比较a和c、b和d，确定解的个数
    // 化简时，我们每次处理1个"单元"，即"+/- n [x]"（x可能不存在），起点为正负号，终点为数字或变量x；依次处理每个单元，累加系数
public:
    string solveEquation(const string &equation) {
        auto div = equation.find_first_of('=');
        auto le = equation.substr(0, div);
        auto re = equation.substr(div + 1);
        auto lc = simplify(le);
        auto rc = simplify(re);
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
    pair<int, int> simplify(string &s) {  // 返回x系数和常数项（若最简式为ax+b，程序返回(a,b)）
        if (s[0] != '+' && s[0] != '-') {
            s = "+" + s;
        }
        const auto n = (int) s.size();
        int a = 0;
        int b = 0;
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
