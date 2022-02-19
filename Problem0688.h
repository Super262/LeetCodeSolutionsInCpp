//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0688_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0688_H

#include <cstring>

using namespace std;

class Solution {
    // 经典动态规划：由内而外汇总结果
    // f[x][i][j]：在(i,j)处，向外走x步后在棋盘上的概率
public:
    double knightProbability(int n, int k, int row, int column) {
        double f[2][n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[0][i][j] = 1;
            }
        }
        const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        const int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
        for (int x = 1; x <= k; ++x) {
            memset(f[x % 2], 0, sizeof f[x % 2]);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int u = 0; u < 8; ++u) {
                        auto ni = i + dx[u];
                        auto nj = j + dy[u];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= n) {
                            continue;
                        }
                        f[x % 2][i][j] += f[(x - 1) % 2][ni][nj] / 8;
                    }
                }
            }
        }
        return f[k % 2][row][column];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0688_H
