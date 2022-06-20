//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0583_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0583_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 动态规划，f[i][j]表示将w1[0:i-1]和w2[0:j-1]调整至相等，需要最少的操作次数
public:
    int minDistance(const string &w1, const string &w2) {
        const auto m = (int) w1.size();
        const auto n = (int) w2.size();
        int f[m + 1][n + 1];
        memset(f, 0x3f, sizeof f);
        for (int l = 0; l <= n; ++l) {
            f[0][l] = l;
        }
        for (int l = 0; l <= m; ++l) {
            f[l][0] = l;
        }
        for (int l1 = 1; l1 <= m; ++l1) {
            for (int l2 = 1; l2 <= n; ++l2) {
                f[l1][l2] = min(f[l1 - 1][l2], f[l1][l2 - 1]) + 1;
                if (w1[l1 - 1] != w2[l2 - 1]) {
                    continue;
                }
                f[l1][l2] = min(f[l1][l2], f[l1 - 1][l2 - 1]);
            }
        }
        return f[m][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0583_H
