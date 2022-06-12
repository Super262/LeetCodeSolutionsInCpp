//
// Created by Fengwei Zhang on 6/12/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0490_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0490_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
    // "拆点" + BFS：图中每个节点是(x,y,d)，d表示球的运动方向
    // 起点是{(sx,sy,d)}，d是某个"畅通的方向"；在起点，球可以尝试向任意畅通方向滚动，我们要遍历所有可能的方向
    // 在路途中，若当前点为(x,y,d)，若d方向畅通，我们继续沿d前进；若d不通，我们尝试其它所有可行方向
    // 注意理解题意：道路畅通时，走到底；道路不通时，尝试所有其它方向
public:
    bool hasPath(const vector<vector<int>> &maze, const vector<int> &start, const vector<int> &dest) {
        const auto m = (int) maze.size();
        const auto n = (int) maze[0].size();
        const int k = 4;
        const int dx[k] = {-1, 1, 0, 0};
        const int dy[k] = {0, 0, -1, 1};
        queue<Node> q;
        bool visited[m][n][k];
        memset(visited, 0, sizeof visited);
        for (int i = 0, x = start[0], y = start[1]; i < k; ++i) {  // 在起点，尝试所有方向
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny]) {
                continue;
            }
            q.push({x, y, i});
            visited[x][y][i] = true;
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto nx = t.x + dx[t.d];
            auto ny = t.y + dy[t.d];
            if (t.x == dest[0] && t.y == dest[1] && (((nx < 0 || nx >= m) || (ny < 0 || ny >= n)) || maze[nx][ny])) {
                return true;
            }
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !maze[nx][ny] && !visited[nx][ny][t.d]) {  // 道路畅通时，走到底
                q.push({nx, ny, t.d});
                visited[nx][ny][t.d] = true;
                continue;
            }
            for (int j = 0; j < k; ++j) {  // 道路不通时，尝试所有其它方向
                auto nd = (t.d + j) % k;
                nx = t.x + dx[nd];
                ny = t.y + dy[nd];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny] || visited[nx][ny][nd]) {
                    continue;
                }
                q.push({nx, ny, nd});
                visited[nx][ny][nd] = true;
            }
        }
        return false;
    }

private:
    struct Node {
        int x;
        int y;
        int d;
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0490_H
