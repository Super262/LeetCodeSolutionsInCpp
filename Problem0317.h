//
// Created by Fengwei Zhang on 5/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0317_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0317_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 从每个建筑物开始BFS，累加所有距离
    // 技巧：利用输入的grid存储中间状态，过滤上次未被遍历过的空地（无效点）
public:
    int shortestDistance(vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        int empty_land = 0;  // 指示当前遍历过程中有效的空地
        int ans = INT_MAX;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] != 1) {
                    continue;
                }
                ans = min(INT_MAX, bfs(x, y, grid, dist, empty_land));
                --empty_land;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

private:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

    int bfs(int sx, int sy, vector<vector<int>> &grid, vector<vector<int>> &dist, int mark) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        int steps = 0;
        int ans = INT_MAX;
        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        while (!q.empty()) {
            ++steps;
            for (int j = (int) q.size(); j > 0; --j) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    auto nx = t.first + dx[i];
                    auto ny = t.second + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != mark) {
                        continue;
                    }
                    --grid[nx][ny];
                    dist[nx][ny] += steps;
                    ans = min(ans, dist[nx][ny]);
                    q.emplace(nx, ny);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0317_H
