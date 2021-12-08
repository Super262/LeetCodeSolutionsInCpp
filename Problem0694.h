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
    // 网格散列：横、纵坐标从左到右依次排列
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
    // 返回连通块的散列值
    string bfs(int x, int y, const vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        string result;
        visited[x][y] = true;
        result += to_string(0);
        result += ',';
        result += to_string(0);
        result += '#';
        q.emplace(x, y);
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
                result += to_string(nx - x);
                result += ',';
                result += to_string(ny - y);
                result += '#';
                q.emplace(nx, ny);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0694_H
