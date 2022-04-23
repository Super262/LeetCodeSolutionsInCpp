//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1034_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1034_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
    // BFS搜索连通块，并标记边界点
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int ans[m][n];  // 0：未被访问；1：被访问；2：被访问，是边界
        queue<pair<int, int>> q;
        memset(ans, 0, sizeof ans);
        ans[row][col] = 1;
        q.emplace(row, col);
        while (!q.empty()) {  // BFS
            auto u = q.front();
            q.pop();
            auto x = u.first;
            auto y = u.second;
            for (int i = 0; i < 4; ++i) {
                auto nx = x + dx[i];
                auto ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != grid[row][col]) {
                    ans[x][y] = 2;
                    continue;
                }
                if (ans[nx][ny]) {
                    continue;
                }
                ans[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
        for (int i = 0; i < m; ++i) {  // 染色
            for (int j = 0; j < n; ++j) {
                if (ans[i][j] != 2) {
                    continue;
                }
                grid[i][j] = color;
            }
        }
        return grid;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1034_H
