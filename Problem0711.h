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
    // 本题是694的加强版，这道题规定两个岛屿若通过平移、旋转和翻转能够重合，它们的形状就相同；首先找出每个岛屿，随后将它进行操作得到各种不同的情况，
    // 接着对这些情况分别进行归一化处理，然后对归一化结果进行哈希得到具有唯一性的签名，最终所有岛屿经所有变换并归一化且哈希后得到的不同签名数量就是满足要求的不同岛屿数量
    // 为了模拟岛屿的旋转和翻转变换，可以先将岛屿的每块陆地坐标(x,y)都看作向量，然后利用解析几何的知识先计算出每个向量变换后的结果，
    // 最终所有通过相同变换后的向量就自然地组成了对应岛屿经相应变换后得到的结果；我们共有6种操作：不操作、水平翻转、垂直翻转、旋转90度、旋转180度、旋转270度（旋转是顺时针）
    // 由于每个操作都具有周期性，且不同操作的组合可能产生相同的结果，我们发现所有操作的组合实现了8种变换：不操作、水平翻转、垂直翻转、旋转90度、旋转180度、旋转270度、旋转90再水平翻转、旋转270再水平翻转
    // 我们依次尝试这8种变换，用集合记录所有最终状态；若集合变大，说明有新状态，递增结果；序列化操作：先将所有坐标偏移到参照点(min_x,min_y)，再排序，再存储到字符串
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
