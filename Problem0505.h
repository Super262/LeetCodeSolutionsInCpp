//
// Created by Fengwei Zhang on 6/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0505_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0505_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem0505 {
    // BFS+贪心，类似Dijkstra算法：设当前位置（队头）是(x,y)，枚举移动方向d（上、下、左、右），并在方向d上走到最远点(nx,ny)（直到进洞或碰壁，贪心思想，将整个滚动路径看作1个点），
    // dist[nx][ny]变小或path[nx][ny]变小，更新dist[nx][ny]和path[nx][ny]，将(nx,ny)压入队列，最后返回目标点的距离
public:
    int shortestDistance(const vector<vector<int>> &maze, const vector<int> &start, const vector<int> &dest) {
        const auto m = (int) maze.size();
        const auto n = (int) maze[0].size();
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int dist[m][n];
        queue<pair<int, int>> q;
        memset(dist, -1, sizeof dist);
        dist[start[0]][start[1]] = 0;
        q.emplace(start[0], start[1]);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto x = t.first;
            auto y = t.second;
            for (int i = 0; i < 4; ++i) {
                auto nx = x + dx[i];
                auto ny = y + dy[i];
                int steps = 1;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && !maze[nx][ny]) {
                    nx += dx[i];
                    ny += dy[i];
                    ++steps;
                }
                nx -= dx[i];
                ny -= dy[i];
                --steps;
                if (!steps || (dist[nx][ny] != -1 && dist[nx][ny] < dist[x][y] + steps)) {
                    continue;
                }
                q.emplace(nx, ny);
                dist[nx][ny] = dist[x][y] + steps;
            }
        }
        return dist[dest[0]][dest[1]];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0505_H
