//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0675_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0675_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    // 直接背诵，特殊的BFS：https://www.acwing.com/solution/content/534/
public:
    int cutOffTree(const vector<vector<int>> &forest) {
        const auto m = (int) forest.size();
        const auto n = (int) forest[0].size();
        vector<Tree> trees;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (forest[x][y] <= 1) {
                    continue;
                }
                trees.push_back({x, y, forest[x][y]});
            }
        }
        sort(trees.begin(), trees.end());
        pair<int, int> st = {0, 0};
        int res = 0;
        for (const auto &t: trees) {
            auto d = bfs(st, {t.x, t.y}, forest);
            if (d == -1) {
                return -1;
            }
            res += d;
            st = {t.x, t.y};
        }
        return res;
    }

private:
    struct Tree {
        int x, y, h;

        bool operator<(Tree &b) const {
            return h < b.h;
        }
    };

    int bfs(const pair<int, int> st, const pair<int, int> ed, const vector<vector<int>> &forest) {
        if (st == ed) {
            return 0;
        }
        const auto m = (int) forest.size();
        const auto n = (int) forest[0].size();
        queue<pair<int, int>> q;
        int dist[m][n];
        memset(dist, -1, sizeof dist);
        q.emplace(st);
        dist[st.first][st.second] = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            auto rx = node.first;
            auto ry = node.second;
            for (int i = 0; i < 4; ++i) {
                auto nx = rx + dx[i];
                auto ny = ry + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || forest[nx][ny] == 0 || dist[nx][ny] != -1) {
                    continue;
                }
                dist[nx][ny] = dist[rx][ry] + 1;
                if (ed.first == nx && ed.second == ny) {
                    return dist[nx][ny];
                }
                q.push({nx, ny});
            }
        }
        return -1;
    }

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0675_H
