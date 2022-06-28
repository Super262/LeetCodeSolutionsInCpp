//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0639_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0639_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // f[i]：长度为i的字符串s，支持的解码方案数（0<=i<=n）；根据题意，s只包含数字，我们可以将1位数或2位数转换为字母（'1'->'A'，'26'->'Z'）
    // 我们枚举字母ch（'A'<=ch<='Z'），检测ch是否能对应到s的尾部；若ch可对应s尾部1个数字，f[i]+=f[i-1]；若ch可对应s尾部2个数字，f[i]+=f[i-2]
public:
    int numDecodings(const string &s) {
        const int M = 1e9 + 7;
        const auto n = (int) s.size();
        int f[3];
        f[0] = 1;
        for (int l = 1; l <= n; ++l) {
            f[l % 3] = 0;  // 使用滑动窗口优化空间时，不要忘记赋初值
            for (int i = 1; i <= 26; ++i) {
                auto a = s[l - 1];
                if (i < 10) {
                    if (a == '*' || a == '0' + i) {
                        f[l % 3] = (int) (((long long) f[(l - 1) % 3] + f[l % 3]) % M);
                    }
                    continue;
                }
                if (l >= 2) {
                    auto b = s[l - 2];
                    auto y = i / 10;
                    auto x = i % 10;
                    if ((b - '0' == y || (y && b == '*')) && (a - '0' == x || (x && a == '*'))) {
                        f[l % 3] = (int) (((long long) f[(l - 2) % 3] + f[l % 3]) % M);
                    }
                }
            }
        }
        return f[n % 3];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0639_H
