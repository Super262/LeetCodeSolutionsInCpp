//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0132_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0132_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0132 {
    // f[i]：前i个字符最少分为f[i]个回文串（i >= 1）
    // 预处理is_pa[i][j]：s[i][j]是否为回文串
public:
    int minCut(const string &s) {
        const int n = (int) s.size();
        bool is_pa[n][n];
        memset(is_pa, 0, sizeof is_pa);
        for (int r = 0; r < n; ++r) {
            for (int l = r; l >= 0; --l) {
                if (l == r) {
                    is_pa[l][r] = true;
                } else {
                    is_pa[l][r] = s[l] == s[r] && (l + 1 > r - 1 || is_pa[l + 1][r - 1]);
                }
            }
        }
        int f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int r = 1; r <= n; ++r) {
            for (int l = 1; l <= r; ++l) {
                if (!is_pa[l - 1][r - 1]) {
                    continue;
                }
                f[r] = min(f[l - 1] + 1, f[r]);
            }
        }
        return f[n] - 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0132_H
