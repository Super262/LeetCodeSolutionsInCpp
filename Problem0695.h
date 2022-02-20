//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0695_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0695_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(const vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        int maximal = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j] || visited[i][j]) {
                    continue;
                }
                maximal = max(maximal, bfs({i, j}, grid, visited, m, n));
            }
        }
        return maximal;
    }

private:
    int bfs(pair<int, int> st, const vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n) {
        queue<pair<int, int>> q;
        int res = 0;
        q.emplace(st);
        visited[st.first][st.second] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            ++res;
            for (int i = 0; i < 4; ++i) {
                auto nx = t.first + dx[i];
                auto ny = t.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || !grid[nx][ny] || visited[nx][ny]) {
                    continue;
                }
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
        return res;
    }

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0695_H
