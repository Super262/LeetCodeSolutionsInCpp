//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0749_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0749_H

#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int containVirus(vector<vector<int>> &grid) {
        int res = 0;
        while (true) {
            auto cnt = scan(grid);
            if (!cnt) {
                break;
            }
            res += cnt;
        }
        return res;
    }

private:
    int scan(vector<vector<int>> &grid) {  // 返回所需防火墙的数量
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maximal = 0;  // 可能被感染的区域的最大值
        int res = 0;  // 防火墙的数量
        vector<set<pair<int, int>>> points_s_list;
        vector<pair<int, int>> path;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1 || visited[i][j]) {
                    continue;
                }
                set<pair<int, int>> points;
                vector<pair<int, int>> temp;
                auto t = dfs(i, j, m, n, visited, temp, points, grid);
                if (points.size() > maximal) {
                    maximal = (int) points.size();
                    res = t;
                    path = temp;
                }
                points_s_list.emplace_back(points);
            }
        }
        for (const auto &p: path) {
            grid[p.first][p.second] = -1;
        }
        for (auto &s: points_s_list) {
            if ((int) s.size() == maximal) {
                continue;
            }
            for (const auto &p: s) {
                grid[p.first][p.second] = 1;
            }
        }
        return res;
    }

    int dfs(int sx, int sy,
            int m, int n,
            vector<vector<bool>> &visited,
            vector<pair<int, int>> &path,
            set<pair<int, int>> &points,
            vector<vector<int>> &grid) {
        visited[sx][sy] = true;
        path.emplace_back(sx, sy);
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            auto nx = sx + dx[i];
            auto ny = sy + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }
            if (grid[nx][ny] == 0) {
                ++res;
                points.insert({nx, ny});
            } else if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                res += dfs(nx, ny, m, n, visited, path, points, grid);
            }
        }
        return res;
    }

    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0749_H
