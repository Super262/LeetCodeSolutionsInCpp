//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0994_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0994_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 多源BFS问题：从所有腐烂点向四周扩散，直至扩散结束
public:
    int orangesRotting(vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }
        int ans = 0;
        if (!q.empty()) {
            --ans;
        }
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        while (!q.empty()) {
            ++ans;
            auto cur_size = (int) q.size();
            while (cur_size--) {
                auto u = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    auto nx = u.first + dx[i];
                    auto ny = u.second + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) {
                        continue;
                    }
                    q.emplace(nx, ny);
                    grid[nx][ny] = 2;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0994_H
