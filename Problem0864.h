//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0864_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0864_H

#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
    // BFS + 拆点：https://www.acwing.com/solution/content/703/
public:
    int shortestPathAllKeys(const vector<string> &grid) {
        int count = 0;  // grid中钥匙的数量
        queue<Node> q;
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(1 << 6, 0x3f3f3f3f)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    q.push({i, j, 0});
                    dist[i][j][0] = 0;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    ++count;
                }
            }
        }
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto t = q.front();
            auto d = dist[t.x][t.y][t.keys];
            q.pop();
            for (int i = 0; i < 4; ++i) {
                auto nx = t.x + dx[i];
                auto ny = t.y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') {
                    continue;
                }
                if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') { // 是钥匙
                    auto next_keys = t.keys | (1 << (grid[nx][ny] - 'a'));
                    if (dist[nx][ny][next_keys] > d + 1) {
                        dist[nx][ny][next_keys] = d + 1;
                        if (next_keys == (1 << count) - 1) {
                            return d + 1;
                        }
                        q.push({nx, ny, next_keys});
                    }
                } else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {  // 是锁
                    if ((t.keys & (1 << (grid[nx][ny] - 'A'))) == 0) {  // 没有钥匙，跳过
                        continue;
                    }
                    if (dist[nx][ny][t.keys] > d + 1) {
                        dist[nx][ny][t.keys] = d + 1;
                        q.push({nx, ny, t.keys});
                    }
                } else {  // 是空地，直接更新距离
                    if (dist[nx][ny][t.keys] > d + 1) {
                        dist[nx][ny][t.keys] = d + 1;
                        q.push({nx, ny, t.keys});
                    }
                }
            }
        }
        return -1;
    }

private:
    struct Node {
        int x;  // 坐标
        int y;
        int keys;  // 当前钥匙序列(11...)
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0864_H
