//
// Created by Fengwei Zhang on 9/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0043_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0043_H

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

class Solution
{
    // 技巧：延迟进位！
public:
    string multiply(const string &num1, const string &num2)
    {
        size_t m = num1.size();
        size_t n = num2.size();

        // 答案长度的上限：两数长度的和
        auto ans_length = m + n;

        unsigned char *a = (unsigned char *)malloc(m * sizeof(unsigned char));
        unsigned char *b = (unsigned char *)malloc(n * sizeof(unsigned char));
        size_t *c = (size_t *)calloc(ans_length, sizeof(size_t));

        // 提取每位数字，从低位开始保存
        numToReversedDigitArray(num1, a);
        numToReversedDigitArray(num2, b);

        // 计算乘积，暂缓进位：C[i + j] = sum(A[i] * B[j])
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                c[i + j] += (size_t)a[i] * b[j];
            }
        }

        // 进位
        for (size_t i = 0, t = 0; i < ans_length; ++i)
        {
            t += c[i];
            c[i] = t % 10;
            t /= 10;
        }

        // 找到第1个非0的最高位
        while (ans_length > 0 && !c[ans_length - 1])
        {
            --ans_length;
        }

        // 若全0，长度自增1
        if (!ans_length)
        {
            ++ans_length;
        }

        // 从高位开始保存结果
        string ans(ans_length, '0');
        for (size_t i = ans_length; i; --i)
        {
            ans[ans_length - i] = (char)(c[i - 1] + '0');
        }

        free(a);
        free(b);
        free(c);

        return ans;
    }

private:
    void numToReversedDigitArray(const string &num, unsigned char *arr)
    {
        size_t n = num.size();
        for (size_t i = n; i; --i)
        {
            arr[n - i] = (unsigned char)(num[i - 1] - '0');
        }
    }
};

#endif // LEETCODESOLUTIONSINCPP_PROBLEM0043_H
