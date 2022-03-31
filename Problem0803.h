//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0803_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0803_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 不能正向操作，每次BFS的搜索空间太大
    // 反向操作，先删除所有被击中的砖块，再依次将其加入，再BFS得出新增稳定砖块的个数
    // https://www.acwing.com/solution/content/7442/
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        vector<int> ans(hits.size(), -1);
        for (auto i = (int) hits.size() - 1; i >= 0; --i) {  // 删去被直接击中的砖块
            if (!grid[hits[i][0]][hits[i][1]]) {
                ans[i] = 0;
            } else {
                grid[hits[i][0]][hits[i][1]] = 0;
            }
        }
        for (int i = 1; i < m; ++i) {  // 标记非顶部的其它砖块
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }
                grid[i][j] = 2;
            }
        }
        vector<pair<int, int>> st;  // 从顶部开始遍历，构建反推的起点
        for (int j = 0; j < n; ++j) {
            if (!grid[0][j]) {
                continue;
            }
            st.emplace_back(0, j);
        }
        bfs(grid, st);
        for (auto i = (int) hits.size() - 1; i >= 0; --i) {
            if (!ans[i]) {
                continue;
            }
            auto hx = hits[i][0];
            auto hy = hits[i][1];
            if (hx != 0 && grid[hx - 1][hy] != 1 && (hx == m - 1 || grid[hx + 1][hy] != 1) &&
                (hy == n - 1 || grid[hx][hy + 1] != 1) && (hy == 0 || grid[hx][hy - 1] != 1)) {  // 删除后不会影响其他砖块
                ans[i] = 0;
                grid[hx][hy] = 2;
            } else {
                grid[hx][hy] = 1;
                st.clear();
                st.emplace_back(hx, hy);
                ans[i] = bfs(grid, st);
            }
        }
        return ans;
    }

private:
    int bfs(vector<vector<int>> &grid, const vector<pair<int, int>> &st) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        for (const auto &p: st) {
            q.emplace(p);
        }
        int ans = 0;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto tx = t.first;
            auto ty = t.second;
            for (int i = 0; i < 4; ++i) {
                auto nx = tx + dx[i];
                auto ny = ty + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 2) {
                    continue;
                }
                grid[nx][ny] = 1;
                q.emplace(nx, ny);
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0803_H
