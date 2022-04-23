//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1039_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1039_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 区间DP：凸多边形划分（AcWing 1069）
    // f[i][j]：所有划分i～j的方案的集合，求最小值；f[i][j] = min{f[i][k] + Wi * Wk * Wj + f[k][j]}，i < k < j
public:
    int minScoreTriangulation(const vector<int> &values) {
        const auto n = (int) values.size();
        int f[n][n];
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i < n; ++i) {
            f[i][i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            f[i - 1][i] = 0;
        }
        for (int length = 3; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                if (length == 3) {
                    f[i][i + 2] = values[i] * values[i + 1] * values[i + 2];
                    continue;
                }
                auto j = i + length - 1;
                for (auto k = i + 1; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + values[i] * values[k] * values[j] + f[k][j]);
                }
            }
        }
        return f[0][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1039_H
