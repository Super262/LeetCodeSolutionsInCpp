//
// Created by Fengwei Zhang on 10/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0010_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0010_H

#include <string>
#include <cstring>

using namespace std;

class Problem0010 {
private:
    bool isMatch(string s, string p) {
        const int n = (int) s.size();
        const int m = (int) p.size();
        bool f[n + 1][m + 1];
        memset(f, 0, sizeof f);
        s = ' ' + s;
        p = ' ' + p;
        f[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j + 1 <= m && p[j + 1] == '*') {
                    continue;
                }
                if (i && p[j] != '*') {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                } else if (p[j] == '*') { // 采用类似于完全背包问题的优化方案
                    f[i][j] = f[i][j - 2] || (i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }
        return f[n][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0010_H
