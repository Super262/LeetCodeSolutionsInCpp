//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0592_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0592_H

#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    string fractionAddition(string exp) {
        int counter = 0;  // 分数个数
        for (const auto &ch: exp) {
            if (ch == '/') {
                ++counter;
            }
        }
        if (exp[0] != '+' && exp[0] != '-') {  // 若表达式起点无运算符，为方便，我们添加"+"
            exp = "+" + exp;
        }
        int a = 0, b = 1;  // 结果的分子和分母
        int offset = 0;  // 当前读取exp到offset位置
        for (int i = 0; i < counter; ++i) {
            int c, d;
            char e;
            sscanf(exp.c_str() + offset, "%c%d/%d", &e, &c, &d);
            // 分数的长度：正负号(1) + 分子长度(log10(x) + 1, x>0) + 分号长度(1) + 分母长度(log10(x) + 1, x>0)
            offset += (1 + ((int) log10(c) + 1) + 1 + ((int) log10(d) + 1));
            if (e == '-') {
                c = -c;
            }
            auto x = a * d + b * c;  // 通分
            auto y = b * d;
            auto z = gcd(x, y);
            a = x / z;
            b = y / z;
        }
        if (b < 0) {  // 若结果为负数，负号加在分子前
            a = -a;
            b = -b;
        }
        return to_string(a) + "/" + to_string(b);
    }

private:
    int gcd(int a, int b) {
        while (b) {
            auto t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0592_H
