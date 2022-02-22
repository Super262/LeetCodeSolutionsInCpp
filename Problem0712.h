//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0712_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0712_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(const string &s1, const string &s2) {
        const auto n = (int) s1.size();
        const auto m = (int) s2.size();
        int f[n + 1][m + 1];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for (int l = 1; l <= m; ++l) {
            f[0][l] = f[0][l - 1] + s2[l - 1];
        }
        for (int l = 1; l <= n; ++l) {
            f[l][0] = f[l - 1][0] + s1[l - 1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                }
                f[i][j] = min(f[i][j], min(f[i - 1][j] + s1[i - 1], f[i][j - 1] + s2[j - 1]));
            }
        }
        return f[n][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0712_H
