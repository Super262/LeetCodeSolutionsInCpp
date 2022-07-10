//
// Created by Fengwei Zhang on 7/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0711_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0711_H

#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

class Problem0711 {
public:
    int numDistinctIslands2(const vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        unordered_set<string> s;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int sx = 0; sx < m; ++sx) {
            for (int sy = 0; sy < n; ++sy) {
                if (!grid[sx][sy] || visited[sx][sy]) {
                    continue;
                }
                auto island = bfs(sx, sy, m, n, grid, visited);
                auto prev_size = s.size();
                s.insert(serializeIsland(island, n));
                s.insert(serializeIsland(rotate90(island), n));
                s.insert(serializeIsland(rotate180(island), n));
                s.insert(serializeIsland(rotate270(island), n));
                s.insert(serializeIsland(reflectLeftRight(island), n));
                s.insert(serializeIsland(reflectUpDown(island), n));
                s.insert(serializeIsland(rotate90(reflectLeftRight(island)), n));
                s.insert(serializeIsland(rotate270(reflectLeftRight(island)), n));
                if (prev_size < s.size()) {
                    ++ans;
                }
            }
        }
        return ans;
    }

private:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

    vector<pair<int, int>> bfs(int sx, int sy, int m, int n, const vector<vector<int>> &grid,
                               vector<vector<bool>> &visited) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> points;
        q.emplace(sx, sy);
        visited[sx][sy] = true;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            points.emplace_back(node.first, node.second);
            for (int i = 0; i < 4; ++i) {
                auto x = node.first + dx[i];
                auto y = node.second + dy[i];
                if (x < 0 || y < 0 || x >= m || y >= n || !grid[x][y] || visited[x][y]) {
                    continue;
                }
                visited[x][y] = true;
                q.emplace(x, y);
            }
        }
        return points;
    }

    string serializeIsland(vector<pair<int, int>> island, int n) {
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        for (const auto &is: island) {
            min_x = min(min_x, is.first);
            min_y = min(min_y, is.second);
        }
        string ans;
        for (auto &is: island) {
            is.first -= min_x;
            is.second -= min_y;
        }
        sort(island.begin(), island.end());
        for (auto &is: island) {
            ans += to_string(is.first * n + is.second) + ',';
        }
        return ans;
    }

    vector<pair<int, int>> rotate90(vector<pair<int, int>> island) {
        for (auto &is: island) {
            swap(is.first, is.second);
            is.second = -is.second;
        }
        return island;
    }

    vector<pair<int, int>> rotate180(vector<pair<int, int>> island) {
        for (auto &is: island) {
            is.first = -is.first;
            is.second = -is.second;
        }
        return island;
    }

    vector<pair<int, int>> rotate270(vector<pair<int, int>> island) {
        for (auto &is: island) {
            swap(is.first, is.second);
            is.first = -is.first;
        }
        return island;
    }

    vector<pair<int, int>> reflectUpDown(vector<pair<int, int>> island) {
        for (auto &is: island) {
            is.second = -is.second;
        }
        return island;
    }

    vector<pair<int, int>> reflectLeftRight(vector<pair<int, int>> island) {
        for (auto &is: island) {
            is.first = -is.first;
        }
        return island;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0711_H
