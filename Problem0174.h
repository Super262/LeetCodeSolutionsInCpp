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
public:
    int calculateMinimumHP(const vector<vector<int>> &dun) {
        const auto m = (int) dun.size();
        const auto n = (int) dun[0].size();
        int f[2][n];  // f[i][j]：在抵达(i, j)前应保有的能量最小值
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                f[i % 2][j] = 0x3f3f3f3f;
                if (i == m - 1 && j == n - 1) {
                    f[i % 2][j] = max(1, 1 - dun[i][j]);  // 终点，能量最少为1
                } else {
                    if (i + 1 < m) {  // 能向下走
                        f[i % 2][j] = min(f[i % 2][j], f[(i + 1) % 2][j] - dun[i][j]);
                    }
                    if (j + 1 < n) {  // 能向右走
                        f[i % 2][j] = min(f[i % 2][j], f[i % 2][j + 1] - dun[i][j]);
                    }
                    f[i % 2][j] = max(1, f[i % 2][j]);
                }
            }
        }
        return f[0][0];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0174_H
