//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0542_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0542_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // BFS，将所有的"0"作为起点，从"0"出发，搜索它的所有邻点，直到无点可搜
public:
    vector<vector<int>> updateMatrix(const vector<vector<int>> &mat) {
        if (mat.empty() || mat[0].empty()) {
            return mat;
        }
        const auto m = (int) mat.size();
        const auto n = (int) mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        const int dx[] = {0, -1, 0, 1};
        const int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < m; ++i) {  // 将所有起点（"0"）压入队列
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    continue;
                }
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto tx = t.first;
            auto ty = t.second;
            for (int i = 0; i < 4; ++i) {
                auto nx = tx + dx[i];
                auto ny = ty + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || dist[nx][ny] != -1) {
                    continue;
                }
                dist[nx][ny] = dist[tx][ty] + 1;  // 更新邻接点的距离
                q.emplace(nx, ny);
            }
        }
        return dist;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0542_H
