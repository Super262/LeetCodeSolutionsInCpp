//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0827_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0827_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int largestIsland(const vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        int parent[m * n];
        int area_size[m * n];
        for (int i = 0; i < m * n; ++i) {
            parent[i] = i;
            area_size[i] = 1;
        }
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int ans = 0;
        for (int x = 0; x < m; ++x) {  // 合并所有连通的的岛屿
            for (int y = 0; y < n; ++y) {
                if (!grid[x][y]) {
                    continue;
                }
                auto pa = findRoot(x * n + y, parent);
                for (int i = 0; i < 4; ++i) {
                    auto nx = x + dx[i];
                    auto ny = y + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || !grid[nx][ny]) {
                        continue;
                    }
                    auto pb = findRoot(nx * n + ny, parent);
                    if (pa == pb) {
                        continue;
                    }
                    area_size[pa] += area_size[pb];
                    parent[pb] = pa;
                }
                ans = max(ans, area_size[pa]);
            }
        }
        unordered_map<int, int> neighbor_size;
        for (int x = 0; x < m; ++x) {  // 尝试将0改为1，记录和四周生成的最大岛屿
            for (int y = 0; y < n; ++y) {
                if (grid[x][y]) {
                    continue;
                }
                for (int i = 0; i < 4; ++i) {
                    auto nx = x + dx[i];
                    auto ny = y + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || !grid[nx][ny]) {
                        continue;
                    }
                    auto pb = findRoot(nx * n + ny, parent);
                    neighbor_size[pb] = area_size[pb];
                }
                int new_island = 1;
                for (const auto &item: neighbor_size) {
                    new_island += item.second;
                }
                ans = max(ans, new_island);
                neighbor_size.clear();
            }
        }
        return ans;
    }

private:
    int findRoot(int x, int parent[]) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0827_H
