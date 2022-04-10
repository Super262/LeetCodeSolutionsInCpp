//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0903_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0903_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 经典动态规划：f[i][j]表示序列[0:i]部分满足s[0:i-1]、最后一个数是j的方案数
    // 掌握映射关系的证明和优化：https://www.acwing.com/solution/content/4531/
public:
    int numPermsDISequence(const string &s) {
        const auto n = (int) s.size();
        const int M = 1e9 + 7;
        int f[n + 1][n + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'D') {
                for (auto j = i - 1; j >= 0; --j) {
                    f[i][j] = (f[i][j + 1] + f[i - 1][j]) % M;
                }
            } else {
                for (int j = 1; j <= i; ++j) {
                    f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % M;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            ans = (ans + f[n][i]) % M;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0903_H
