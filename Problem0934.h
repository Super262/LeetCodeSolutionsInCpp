//
// Created by Fengwei Zhang on 4/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0934_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0934_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 首先，通过DFS搜索到第一个连通块中所有的点；然后，通过BFS探索当前连通块到其它连通块的最短距离（多源最短路）
public:
    int shortestBridge(const vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                vector<vector<bool>> in_comp(m, vector<bool>(n, false));
                queue<pair<int, int>> q;
                vector<vector<int>> dist(m, vector<int>(n, 0x3f3f3f3f));
                dfsGetComp(i, j, grid, in_comp, q, dist);
                return bfs(q, grid, in_comp, dist);
            }
        }
        return -1;
    }

private:
    void dfsGetComp(int sx,
                    int sy,
                    const vector<vector<int>> &grid,
                    vector<vector<bool>> &in_comp,
                    queue<pair<int, int>> &comp,
                    vector<vector<int>> &dist) {
        in_comp[sx][sy] = true;
        dist[sx][sy] = 0;
        comp.emplace(sx, sy);
        for (int i = 0; i < 4; ++i) {
            auto nx = sx + dx[i];
            auto ny = sy + dy[i];
            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || !grid[nx][ny] || in_comp[nx][ny]) {
                continue;
            }
            dfsGetComp(nx, ny, grid, in_comp, comp, dist);
        }
    }

    int bfs(queue<pair<int, int>> &q,
            const vector<vector<int>> &grid,
            const vector<vector<bool>> &in_comp,
            vector<vector<int>> &dist) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto sx = t.first;
            auto sy = t.second;
            auto ud = dist[sx][sy];
            for (int i = 0; i < 4; ++i) {
                auto nx = sx + dx[i];
                auto ny = sy + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || in_comp[nx][ny] || dist[nx][ny] <= ud + 1) {
                    continue;
                }
                if (grid[nx][ny]) {  // 发现另一个连通块
                    return ud;
                }
                dist[nx][ny] = ud + 1;
                q.emplace(nx, ny);
            }
        }
        return -1;
    }

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0934_H
