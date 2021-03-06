//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0174_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0174_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 经典DP，必须掌握：已知最终状态（能量大于0），反推初始值
    // f[i][j]：想到达终点，从(i, j)出发时应保有的能量最小值
public:
    int calculateMinimumHP(const vector<vector<int>> &dun) {
        const auto m = (int) dun.size();
        const auto n = (int) dun[0].size();
        int f[2][n];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                f[i % 2][j] = 0x3f3f3f3f;  // 不要忘记这个初始化，因为这里有空间优化
                if (i == m - 1 && j == n - 1) {
                    f[i % 2][j] = max(1, 1 - dun[i][j]);  // 终点，能量最少为1
                } else {
                    if (i + 1 < m) {  // 能向下走
                        f[i % 2][j] = min(f[i % 2][j], f[(i + 1) % 2][j] - dun[i][j]);
                    }
                    if (j + 1 < n) {  // 能向右走
                        f[i % 2][j] = min(f[i % 2][j], f[i % 2][j + 1] - dun[i][j]);
                    }
                    f[i % 2][j] = max(1, f[i % 2][j]);  // 最后必须保证起点的能量大于0
                }
            }
        }
        return f[0][0];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0174_H
