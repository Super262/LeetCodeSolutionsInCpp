//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0200_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0200_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        const int m = (int) grid.size();
        const int n = (int) grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
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
    void bfs(const int &x, const int &y, vector<vector<char>> &grid) {
        const int m = (int) grid.size();
        const int n = (int) grid[0].size();
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        q.emplace(pair<int, int>(x, y));
        grid[x][y] = '0';
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                auto nx = root.first + dx[i];
                auto ny = root.second + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '0') {
                    continue;
                }
                q.emplace(pair<int, int>(nx, ny));
                grid[nx][ny] = '0';
            }
        }
    }

};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0200_H
