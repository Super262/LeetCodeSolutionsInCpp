//
// Created by Fengwei Zhang on 6/12/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0499_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0499_H

#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
    // BFS+贪心：设当前位置（队头）是(x,y)，枚举移动方向d（上、下、左、右），并在方向d上走到最远点(nx,ny)（直到进洞或碰壁，贪心思想，将整个滚动路径看作1个点），
    // dist[nx][ny]变小或path[nx][ny]变小，更新dist[nx][ny]和path[nx][ny]，将(nx,ny)压入队列
public:
    string findShortestWay(const vector<vector<int>> &maze, const vector<int> &ball, const vector<int> &hole) {
        const auto m = (int) maze.size();
        const auto n = (int) maze[0].size();
        const int k = 4;
        const int dx[k] = {-1, 1, 0, 0};
        const int dy[k] = {0, 0, -1, 1};
        const char dch[k] = {'u', 'd', 'l', 'r'};
        int dist[m][n];
        string path[m][n];
        queue<pair<int, int>> q;
        memset(dist, 0x3f, sizeof dist);
        dist[ball[0]][ball[1]] = 0;
        path[ball[0]][ball[1]] = "";
        q.emplace(ball[0], ball[1]);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto x = t.first;
            auto y = t.second;
            for (int i = 0; i < k; ++i) {
                auto nx = x + dx[i];
                auto ny = y + dy[i];
                auto steps = 1;
                auto np = path[x][y] + dch[i];
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && !maze[nx][ny] &&
                       !(nx - dx[i] == hole[0] && ny - dy[i] == hole[1])) {  // 贪心
                    nx += dx[i];
                    ny += dy[i];
                    ++steps;
                }
                nx -= dx[i];
                ny -= dy[i];
                --steps;
                if (!steps) {
                    continue;
                }
                if (steps + dist[x][y] < dist[nx][ny] || (steps + dist[x][y] == dist[nx][ny] && np < path[nx][ny])) {
                    dist[nx][ny] = steps + dist[x][y];
                    path[nx][ny] = np;
                    if (nx != hole[0] || ny != hole[1]) {
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        return dist[hole[0]][hole[1]] == 0x3f3f3f3f ? "impossible" : path[hole[0]][hole[1]];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0499_H
