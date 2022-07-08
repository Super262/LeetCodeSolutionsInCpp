//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0694_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0694_H

#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    // 首先，我们通过BFS搜索出每个岛屿，返回散列值s（字符串）；利用哈希表统计不同散列值的个数
    // 岛屿的散列值s是从搜索起点到终点的坐标序列（字符串），分隔符为"#"，如"0,0#0,1#1,1#"
public:
    int numDistinctIslands(const vector<vector<int>> &grid) {
        unordered_set<string> islands;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0 || visited[i][j]) {
                    continue;
                }
                islands.insert(bfs(i, j, grid, visited));
            }
        }
        return (int) islands.size();
    }

private:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    // 返回连通块的散列值
    string bfs(int sx, int sy, const vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        queue<pair<int, int>> q;
        string ans;
        visited[sx][sy] = true;
        ans += to_string(0);
        ans += ',';
        ans += to_string(0);
        ans += '#';
        q.emplace(sx, sy);
        while (!q.empty()) {
            auto st = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                auto nx = st.first + dx[i];
                auto ny = st.second + dy[i];
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 0) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }
                visited[nx][ny] = true;
                ans += to_string(nx - sx);
                ans += ',';
                ans += to_string(ny - sy);
                ans += '#';
                q.emplace(nx, ny);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0694_H
