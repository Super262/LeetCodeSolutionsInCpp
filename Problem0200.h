//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0200_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0200_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 从每个"1"开始BFS，标记被发现的岛屿为"0"；统计岛屿数量
public:
    int numIslands(vector<vector<char>> &grid) {
        int result = 0;
        for (int i = 0; i < (int) grid.size(); ++i) {
            for (int j = 0; j < (int) grid[0].size(); ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }
                bfs(i, j, grid);
                ++result;
            }
        }
        return result;
    }

private:
    void bfs(const int rx, const int ry, vector<vector<char>> &grid) {
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        q.emplace(rx, ry);
        grid[rx][ry] = '0';
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                auto nx = root.first + dx[i];
                auto ny = root.second + dy[i];
                if (nx < 0 || nx >= (int) grid.size() || ny < 0 || ny >= (int) grid[0].size() || grid[nx][ny] == '0') {
                    continue;
                }
                q.emplace(nx, ny);
                grid[nx][ny] = '0';
            }
        }
    }

};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0200_H
