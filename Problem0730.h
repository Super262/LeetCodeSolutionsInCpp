//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0730_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0730_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 动态规划 + 滑动窗口：https://www.acwing.com/solution/content/4105/
    // f[i][j]：闭区间[i:j]中回文串的个数，包含空串
public:
    int countPalindromicSubsequences(const string &s) {
        const int M = 1e9 + 7;
        const auto n = (int) s.size();
        int f[n][n];
        int st[4];  // [i:j]中字符的最左索引
        int ed[4];  // [i:j]中字符的最右索引
        memset(f, 0, sizeof f);
        memset(st, -1, sizeof st);
        for (int i = n - 1; i >= 0; --i) {
            st[s[i] - 'a'] = i;
            memset(ed, -1, sizeof ed);
            for (int j = i; j < n; ++j) {
                f[i][j] = 1;  // 添加空串
                ed[s[j] - 'a'] = j;
                for (int c = 0; c < 4; ++c) {
                    if (st[c] == -1 || ed[c] == -1) {
                        continue;
                    }
                    f[i][j] = (f[i][j] + 1) % M;  // 添加单字符回文串
                    if (st[c] == ed[c]) {
                        continue;
                    }
                    if (ed[c] == st[c] + 1) {  // 添加双字符回文串
                        f[i][j] = (f[i][j] + 1) % M;
                    } else {  // 添加其他类型回文串
                        f[i][j] = (int) (((long long) f[i][j] + f[st[c] + 1][ed[c] - 1]) % M);
                    }
                }
            }
        }
        return ((f[0][n - 1] - 1) % M + M) % M;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0730_H
