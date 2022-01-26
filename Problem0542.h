//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0542_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0542_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(const vector<vector<int>> &mat) {
        if (mat.empty() || mat[0].empty()) {
            return mat;
        }
        const auto n = (int) mat.size();
        const auto m = (int) mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        const int dx[] = {0, -1, 0, 1};
        const int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
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
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || dist[nx][ny] != -1) {
                    continue;
                }
                dist[nx][ny] = dist[tx][ty] + 1;
                q.emplace(nx, ny);
            }
        }
        return dist;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0542_H
