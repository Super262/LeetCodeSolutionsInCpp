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

        // 提取每位数字，从低位开始保存
        for (auto i = m - 1, j = 0; i >= 0; --i, ++j) {
            a[j] = num1[i] - '0';
        }
        for (auto i = n - 1, j = 0; i >= 0; --i, ++j) {
            b[j] = num2[i] - '0';
        }

        // 计算乘积，暂缓进位：C[i + j] = sum(A[i] * B[j])
        int c[m + n];
        memset(c, 0, sizeof c);
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
        auto num_end = m + n - 1;
        while (num_end > 0 && c[num_end] == 0) {// 注意细节：设置"num_end > 0"而不是"num_end >= 0"，因为结果的最小长度应大于0
            --num_end;
        }

        // 从高位开始保存结果
        string result(num_end + 1, '0');
        for (int i = 0; i <= num_end; ++i) {
            result[result.size() - 1 - i] = (char) (c[i] + '0');
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0043_H
