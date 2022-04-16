//
// Created by Fengwei Zhang on 4/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0940_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0940_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // f[i][ch]：选取自前i个字母、结尾为字符ch的所有不同子序列的方案数，i >= 1
    // 若s[i - 1] != ch，f[i][ch] = f[i - 1][ch]
    // 若s[i - 1] == ch，若s[i - 1]是前i个字符中唯一的ch，f[i][ch] = 1；f[i][ch] = sum{f[i - 1][x], 'a' <= x <= 'z'}
    // 使得以上等式成立的关键结论：以字符ch结尾的方案数 == 以字符s[i - 1]结尾的方案数
public:
    int distinctSubseqII(const string &s) {
        const int M = 1e9 + 7;
        const int K = 26;
        const auto n = (int) s.size();
        int f[n + 1][K];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; ++i) {
            memcpy(f[i], f[i - 1], sizeof f[i - 1]);  // s[i - 1] != ch
            auto ch = s[i - 1] - 'a';
            int prev_sum = 0;
            for (int j = 0; j < K; ++j) {
                prev_sum = (prev_sum + f[i - 1][j]) % M;
            }
            f[i][ch] = (1 + prev_sum) % M;  // s[i - 1] == ch
        }
        int ans = 0;
        for (int j = 0; j < K; ++j) {
            ans = (ans + f[n][j]) % M;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0940_H
