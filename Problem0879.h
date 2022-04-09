//
// Created by Fengwei Zhang on 4/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0879_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0879_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 类比AcWing 1020
public:
    int profitableSchemes(int n, int m, const vector<int> &group, const vector<int> &profit) {
        const int M = 1e9 + 7;
        int f[n + 1][m + 1];
        memset(f, 0, sizeof f);
        for (int i = 0; i <= n; ++i) {
            f[i][0] = 1;
        }
        for (int k = 0; k < profit.size(); ++k) {
            auto c = group[k];
            auto p = profit[k];
            for (int i = n; i >= c; --i) {
                for (int j = m; j >= 0; --j) {
                    f[i][j] += f[i - c][max(0, j - p)];
                    f[i][j] %= M;
                }
            }
        }
        return f[n][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0879_H
