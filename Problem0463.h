//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0463_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0463_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 最优解：无需BFS，搜索连通分量：枚举到方向i时，若i方向的可能值是无效的，说明i所在的边是边界，周长加1
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int res = 0;
        const auto n = (int) grid.size();
        const auto m = (int) grid[0].size();
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (grid[x][y] != 1) {
                    continue;
                }
                for (int i = 0; i < 4; ++i) {
                    auto nx = x + dx[i];
                    auto ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || !grid[nx][ny]) {
                        ++res;
                    }
                }
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0463_H
