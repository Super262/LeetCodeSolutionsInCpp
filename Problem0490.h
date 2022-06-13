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
    // 优化：利用贪心省略拆点过程，枚举移动方向d（上、下、左、右），并在方向d上走到最远点(nx,ny)（直到进洞或碰壁，贪心思想，将整个滚动路径看作1个点）
public:
    bool hasPath(const vector<vector<int>> &maze, const vector<int> &start, const vector<int> &dest) {
        // 优化后的解法
        const auto m = (int) maze.size();
        const auto n = (int) maze[0].size();
        const int k = 4;
        const int dx[k] = {-1, 1, 0, 0};
        const int dy[k] = {0, 0, -1, 1};
        bool visited[m][n];
        queue<pair<int, int>> q;
        memset(visited, 0, sizeof visited);
        q.emplace(start[0], start[1]);
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto x = t.first;
            auto y = t.second;
            if (x == dest[0] && y == dest[1]) {
                return true;
            }
            for (int i = 0; i < k; ++i) {
                auto nx = x + dx[i];
                auto ny = y + dy[i];
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && !maze[nx][ny]) {
                    nx += dx[i];
                    ny += dy[i];
                }
                nx -= dx[i];
                ny -= dy[i];
                if (visited[nx][ny]) {
                    continue;
                }
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
        return false;
    }
    /*
    bool hasPath(const vector<vector<int>> &maze, const vector<int> &start, const vector<int> &dest) {
        // 初始解法
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
    */
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0490_H
