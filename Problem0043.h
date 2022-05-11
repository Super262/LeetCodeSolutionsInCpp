//
// Created by Fengwei Zhang on 9/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0043_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0043_H

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
    // 技巧：延迟进位！
public:
    string multiply(const string &num1, const string &num2) {
        const auto m = (int) num1.size();
        const auto n = (int) num2.size();
        int a[m];
        int b[n];
        int c[m + n];
        memset(c, 0, sizeof c);

        // 提取每位数字，从低位开始保存
        for (int i = m - 1, j = 0; i >= 0; --i, ++j) {
            a[j] = num1[i] - '0';
        }
        for (int i = n - 1, j = 0; i >= 0; --i, ++j) {
            b[j] = num2[i] - '0';
        }

        // 计算乘积，暂缓进位：C[i + j] = sum(A[i] * B[j])
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i + j] += a[i] * b[j];
            }
        }

        // 进位
        for (int i = 0, t = 0; i < m + n; ++i) {
            t += c[i];
            c[i] = t % 10;
            t /= 10;
        }

        // 找到第1个非0的最高位
        auto ans_end = m + n - 1;
        while (ans_end > 0 && !c[ans_end]) {
            --ans_end;
        }

        // 从高位开始保存结果
        string ans(ans_end + 1, '0');
        for (int i = ans_end, j = 0; i >= 0; --i, ++j) {
            ans[j] = (char) (c[i] + '0');
        }

        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0043_H
