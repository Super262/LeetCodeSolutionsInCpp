//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0741_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0741_H

#include <vector>

using namespace std;

class Problem0741 {
    // 经典DP，参见AcWing1027；f[s][x1][x2]表示从(1,1)走到(n,n)的两条路径的长度和的最大值，s=x1+y1=x2+y2
    // 这里我们假设左上角为(1,1)、右下角为(n,n)；
public:
    int cherryPickup(const vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        int f[2][m + 1][m + 1];
        memset(f[2 % 2], -0x3f, sizeof f[2 % 2]);
        f[2 % 2][1][1] = grid[0][0];
        for (int s = 3; s <= m + n; ++s) {
            memset(f[s % 2], -0x3f, sizeof f[s % 2]);
            for (auto x1 = max(1, s - n); x1 <= min(n, s - 1); ++x1) {
                for (auto x2 = max(1, s - n); x2 <= min(n, s - 1); ++x2) {
                    auto y1 = s - x1;
                    auto y2 = s - x2;
                    if (grid[x1 - 1][y1 - 1] == -1 || grid[x2 - 1][y2 - 1] == -1) {
                        continue;
                    }
                    auto w = grid[x1 - 1][y1 - 1];
                    if (x1 != x2 && y1 != y2) {
                        w += grid[x2 - 1][y2 - 1];
                    }
                    f[s % 2][x1][x2] = max(f[s % 2][x1][x2], f[(s - 1) % 2][x1][x2] + w);
                    f[s % 2][x1][x2] = max(f[s % 2][x1][x2], f[(s - 1) % 2][x1 - 1][x2 - 1] + w);
                    f[s % 2][x1][x2] = max(f[s % 2][x1][x2], f[(s - 1) % 2][x1][x2 - 1] + w);
                    f[s % 2][x1][x2] = max(f[s % 2][x1][x2], f[(s - 1) % 2][x1 - 1][x2] + w);
                }
            }
        }
        return max(0, f[(m + n) % 2][m][m]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0741_H
