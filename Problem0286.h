//
// Created by Fengwei Zhang on 5/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0286_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0286_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
    // 多源BFS
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        const auto m = (int) rooms.size();
        const auto n = (int) rooms[0].size();
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (rooms[x][y]) {
                    continue;
                }
                q.emplace(x, y);
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto x = t.first;
            auto y = t.second;
            auto d = rooms[x][y];
            for (int i = 0; i < 4; ++i) {
                auto nx = x + dx[i];
                auto ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || rooms[nx][ny] == -1 || rooms[nx][ny] <= d + 1) {
                    continue;
                }
                rooms[nx][ny] = d + 1;
                q.emplace(nx, ny);
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0286_H
