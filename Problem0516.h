//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0516_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0516_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 区间DP：f[i][j]表示s[i:j]段回文子序列最大长度
public:
    int longestPalindromeSubseq(const string &s) {
        const auto n = (int) s.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                auto j = i + length - 1;
                if (s[i] == s[j]) {
                    f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
                }
                f[i][j] = max(f[i][j], max(f[i][j - 1], f[i + 1][j]));
            }
        }
        return f[0][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0516_H
