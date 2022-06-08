//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0474_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0474_H

#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Solution {
    // 转化原题为"二维背包"，类似AcWing 1020
    // f[i][j]=k表示含"0"数不超过i、含"1"数不超过j时，最多可选择k个单词
public:
    int findMaxForm(const vector<string> &strs, int m, int n) {
        int f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        for (const auto &s: strs) {
            int a = 0;
            int b = 0;
            for (const auto &ch: s) {
                if (ch == '0') {
                    ++a;
                } else {
                    ++b;
                }
            }
            for (int i = m; i >= a; --i) {
                for (int j = n; j >= b; --j) {
                    f[i][j] = max(f[i][j], f[i - a][j - b] + 1);
                }
            }
        }
        return f[m][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0474_H
