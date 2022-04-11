//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0909_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0909_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
    // 预处理，存储"编号-坐标"映射和"坐标-编号"映射；直接BFS
public:
    int snakesAndLadders(const vector<vector<int>> &board) {
        const auto m = (int) board.size();
        const auto n = (int) board[0].size();
        int pos_to_id[m][n];
        pair<int, int> id_to_pos[m * n + 1];
        for (int i = m - 1, k = 1; i >= 0; --i) {  // 从第(m-1)行开始，建立映射
            if ((m - 1 - i) % 2) {
                for (int j = n - 1; j >= 0; --j) {
                    id_to_pos[k].first = i;
                    id_to_pos[k].second = j;
                    pos_to_id[i][j] = k;
                    ++k;
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    id_to_pos[k].first = i;
                    id_to_pos[k].second = j;
                    pos_to_id[i][j] = k;
                    ++k;
                }
            }
        }
        queue<int> q;
        int dist[m * n + 1];
        memset(dist, 0x3f, sizeof dist);
        dist[1] = 0;
        q.emplace(1);
        while (!q.empty()) {
            auto t = q.front();
            if (t == m * n) {
                return dist[t];
            }
            q.pop();
            for (int i = 1; i <= 6 && t + i <= n * m; ++i) {
                auto x = id_to_pos[t + i].first;
                auto y = id_to_pos[t + i].second;
                auto u = t + i;
                if (board[x][y] != -1) {
                    u = board[x][y];
                }
                if (dist[u] <= dist[t] + 1) {
                    continue;
                }
                dist[u] = dist[t] + 1;
                q.emplace(u);
            }
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0909_H
