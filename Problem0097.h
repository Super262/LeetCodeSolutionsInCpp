//
// Created by Fengwei Zhang on 10/31/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0097_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0097_H

#include <string>
#include <cstring>

using namespace std;

class Problem0097 {
    // f[i][j]：s1[0:i-1]和s2[0:j-1]组成s3[0:i+j-1]，最后的字符来自s1或s2
public:
    bool isInterleave(const string &s1, const string &s2, const string &s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        const auto m = (int) s1.size();
        const auto n = (int) s2.size();
        bool f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i && s1[i - 1] == s3[i + j - 1]) {
                    f[i][j] = f[i][j] || f[i - 1][j];
                }
                if (j && s2[j - 1] == s3[i + j - 1]) {
                    f[i][j] = f[i][j] || f[i][j - 1];
                }
            }
        }
        return f[m][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0097_H
