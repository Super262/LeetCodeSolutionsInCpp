//
// Created by Fengwei Zhang on 9/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0043_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0043_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Problem0043 {
private:
    // 技巧：延迟进位！
    string multiply(string num1, string num2) {
        vector<int> a(num1.size(), 0);
        vector<int> b(num2.size(), 0);

        // 提取每位数字，从低位开始保存
        for (int i = (int) num1.size() - 1, j = 0; i >= 0; --i, ++j) {
            a[j] = num1[i] - '0';
        }
        for (int i = (int) num2.size() - 1, j = 0; i >= 0; --i, ++j) {
            b[j] = num2[i] - '0';
        }

        // 计算乘积，暂缓进位
        vector<int> c(num1.size() + num2.size(), 0);
        for (int i = 0; i < (int) a.size(); ++i) {
            for (int j = 0; j < (int) b.size(); ++j) {
                c[i + j] += a[i] * b[j];
            }
        }

        // 进位
        for (int i = 0, t = 0; i < (int) c.size(); ++i) {
            t += c[i];
            c[i] = t % 10;
            t /= 10;
        }

        // 找到第1个非0高位
        auto highStart = (int) c.size() - 1;
        while (highStart > 0 && c[highStart] == 0) {
            --highStart;
        }

        // 从高位开始保存结果
        string result(highStart + 1, '0');
        for (int i = 0; i <= highStart; ++i) {
            result[highStart - i] = (char) (c[i] + '0');
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0043_H
