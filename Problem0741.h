//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0741_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0741_H

#include <vector>

using namespace std;

class Solution {
    // 经典DP，参见提高课
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
