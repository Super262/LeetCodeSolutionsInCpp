//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0712_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0712_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 动态规划，f[i][j]表示将s1的前i个字符、s2的前j个字符调整为相等的序列，需要删除的字符的最小加和
    // 初始时，f[0][i]=f[0][i-1]+s2[i-1]，f[i][0]=f[i-1][0]+s1[i-1]；转移时，若s1[i-1]=s2[i-1]，f[i][j]=min({f[i-1][j-1]})
    // 若s1[i-1]!=s2[i-1]，f[i][j]=min({f[i-1][j]+s1[i-1]},{f[i][j-1]+s2[j-1]})
public:
    int minimumDeleteSum(const string &s1, const string &s2) {
        const auto m = (int) s1.size();
        const auto n = (int) s2.size();
        int f[m + 1][n + 1];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for (int l = 1; l <= m; ++l) {
            f[l][0] = f[l - 1][0] + s1[l - 1];
        }
        for (int l = 1; l <= n; ++l) {
            f[0][l] = f[0][l - 1] + s2[l - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                }
                f[i][j] = min(f[i][j], min(f[i - 1][j] + s1[i - 1], f[i][j - 1] + s2[j - 1]));
            }
        }
        return f[m][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0712_H
