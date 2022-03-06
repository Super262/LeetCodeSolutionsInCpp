//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0749_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0749_H

#include <set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int containVirus(vector<vector<int>> &grid) {
        int walls = 0;
        while (true) {
            auto cnt = scan(grid);
            if (!cnt) {
                break;
            }
            walls += cnt;
        }
        return walls;
    }

private:
    int scan(vector<vector<int>> &grid) {  // 返回所需防火墙的数量
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int max_risk = 0;  // 可能被感染的区域的最大值
        int walls = 0;  // 防火墙的数量
        vector<set<pair<int, int>>> risk_points_list;  // 即将被感染的点
        vector<pair<int, int>> infected_points;  // 风险点最多的被感染区域
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1 || visited[i][j]) {
                    continue;
                }
                set<pair<int, int>> risk_points;
                vector<pair<int, int>> temp;
                auto t = countWalls(i, j, m, n, visited, temp, risk_points, grid);
                if (risk_points.size() > max_risk) {
                    max_risk = (int) risk_points.size();
                    walls = t;
                    infected_points = temp;
                }
                risk_points_list.emplace_back(risk_points);
            }
        }
        for (const auto &p: infected_points) {  // 标记被选中的感染区域，避免重复搜索
            grid[p.first][p.second] = -1;
        }
        for (const auto &s: risk_points_list) {  // 标记所有未被隔离的风险点为"被感染"
            if ((int) s.size() == max_risk) {
                continue;
            }
            for (const auto &p: s) {
                grid[p.first][p.second] = 1;
            }
        }
        return walls;
    }

    int countWalls(int sx,
                   int sy,
                   int m,
                   int n,
                   vector<vector<bool>> &visited,
                   vector<pair<int, int>> &infected_points,
                   set<pair<int, int>> &risk_points,
                   const vector<vector<int>> &grid) {
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, 1, 0, -1};
        int walls = 0;
        queue<pair<int, int>> q;
        visited[sx][sy] = true;
        q.emplace(sx, sy);
        infected_points.emplace_back(sx, sy);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            sx = p.first;
            sy = p.second;
            for (int i = 0; i < 4; ++i) {
                auto nx = sx + dx[i];
                auto ny = sy + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    continue;
                }
                if (grid[nx][ny] == 0) {
                    ++walls;
                    risk_points.insert({nx, ny});
                } else if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                    infected_points.emplace_back(nx, ny);
                }
            }
        }
        return walls;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0749_H
