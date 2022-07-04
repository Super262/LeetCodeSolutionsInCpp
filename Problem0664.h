//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0664_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0664_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 区间DP，f[l][r]表示将[l:r]染色为最终样子的最少操作次数；若先打印s[l]，再打印s[l:r]，操作次数为f[l+1][r]+1，这也是f[l][r]的初始值
    // 若s[l+1]=s[l]，那么f[l][r]=f[l][l]+f[l+2][r]；否则，f[l][r]=f[l][l+1]+f[l+2][r]
    // 以此类推，若s[k]=s[l]，那么f[l][r]=f[l][k-1]+f[k+1][r]；否则，f[l][r]=f[l][k]+f[k+1][r]
    // 类似矩阵连乘，https://www.acwing.com/solution/content/5208/
public:
    int strangePrinter(const string &s) {
        const auto n = (int) s.size();
        int f[n + 1][n + 1];
        memset(f, 0, sizeof f);
        for (int length = 1; length <= n; ++length) {
            for (int l = 0; l + length - 1 < n; ++l) {
                auto r = l + length - 1;
                f[l][r] = 1 + f[l + 1][r];
                for (auto k = l + 1; k <= r; ++k) {
                    if (s[k] == s[l]) {
                        f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r]);
                    } else {
                        f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0664_H
