//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0764_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0764_H

#include <vector>

using namespace std;

class Problem0764 {
    // f[i][j]：(i,j)向外延伸的最小值
public:
    int orderOfLargestPlusSign(int n, const vector<vector<int>> &mines) {
        bool grid[n][n];
        int f[n][n];
        memset(grid, 0, sizeof grid);
        memset(f, 0x3f, sizeof f);
        for (const auto &m: mines) {
            grid[m[0]][m[1]] = true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0, s = 0; j < n; ++j) {  // 左延伸
                if (grid[i][j]) {
                    s = 0;
                } else {
                    ++s;
                }
                f[i][j] = min(s, f[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1, s = 0; j >= 0; --j) {  // 右延伸
                if (grid[i][j]) {
                    s = 0;
                } else {
                    ++s;
                }
                f[i][j] = min(s, f[i][j]);
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0, s = 0; i < n; ++i) {  // 上延伸
                if (grid[i][j]) {
                    s = 0;
                } else {
                    ++s;
                }
                f[i][j] = min(s, f[i][j]);
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = n - 1, s = 0; i >= 0; --i) {  // 下延伸
                if (grid[i][j]) {
                    s = 0;
                } else {
                    ++s;
                }
                f[i][j] = min(s, f[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, f[i][j]);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0764_H
