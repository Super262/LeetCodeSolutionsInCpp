//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0417_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0417_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 从两个大洋的边界点向内部BFS，搜索出所有可行的路径，分别标记（二进制数的最低2位）
public:
    vector<vector<int>> pacificAtlantic(const vector<vector<int>> &heights) {
        const int m = (int) heights.size();
        const int n = (int) heights[0].size();
        vector<vector<int>> st(m, vector<int>(n, 0));  // 11：从两个方向可达；01：从太平洋可达；10：从大西洋可达
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {  // 太平洋的边界：上边
            q.emplace(i, 0);
            st[i][0] |= 1;
        }
        for (int i = 1; i < n; ++i) {  // 太平洋的边界：左边
            q.emplace(0, i);
            st[0][i] |= 1;
        }
        bfs(1, heights, q, st);
        q = queue<pair<int, int>>();
        for (int i = 0; i < m; ++i) {  // 大西洋的边界：右边
            q.emplace(i, n - 1);
            st[i][n - 1] |= 2;
        }
        for (int i = 0; i < n - 1; ++i) {  // 大西洋的边界：下边
            q.emplace(m - 1, i);
            st[m - 1][i] |= 2;
        }
        bfs(2, heights, q, st);
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (st[i][j] != 3) {
                    continue;
                }
                ans.push_back({i, j});
            }
        }
        return ans;
    }

private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    void bfs(int tag, const vector<vector<int>> &heights, queue<pair<int, int>> &q, vector<vector<int>> &st) {
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            auto x = p.first;
            auto y = p.second;
            for (int i = 0; i < 4; ++i) {
                auto nx = x + dx[i];
                auto ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= (int) heights.size() || ny >= (int) heights[0].size() ||
                    heights[nx][ny] < heights[x][y] || ((st[nx][ny] >> (tag - 1)) & 1)) {
                    continue;
                }
                q.emplace(nx, ny);
                st[nx][ny] |= tag;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0417_H
