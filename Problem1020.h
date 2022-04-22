//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1020_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1020_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // BFS：从边界岛屿搜索
public:
    int numEnclaves(vector<vector<int>> &grid) {
        queue<pair<int, int>> q;
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        for (int i = 0; i < n; ++i) {  // 上、下边界
            if (grid[0][i]) {
                q.emplace(0, i);
                grid[0][i] = 2;
            }
            if (m > 1 && grid[m - 1][i]) {
                q.emplace(m - 1, i);
                grid[m - 1][i] = 2;
            }
        }
        for (int i = 1; i < m - 1; ++i) {  // 左、右边界
            if (grid[i][0]) {
                q.emplace(i, 0);
                grid[i][0] = 2;
            }
            if (n > 1 && grid[i][n - 1]) {
                q.emplace(i, n - 1);
                grid[i][n - 1] = 2;
            }
        }
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {-1, 0, 1, 0};
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            auto sx = u.first;
            auto sy = u.second;
            for (int i = 0; i < 4; ++i) {
                auto nx = sx + dx[i];
                auto ny = sy + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || !grid[nx][ny] || grid[nx][ny] == 2) {
                    continue;
                }
                q.emplace(nx, ny);
                grid[nx][ny] = 2;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++ans;
                }
            }
        }
        for (int i = 0; i < m; ++i) {  // 恢复现场
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1020_H
