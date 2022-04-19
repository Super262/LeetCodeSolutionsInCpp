//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0980_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0980_H

#include <vector>

using namespace std;

class Solution {
    // 最优解：插头DP，太复杂（AcWing进阶课）
    // 由于数据范围较小，这里直接DFS探索所有可行路径
public:
    int uniquePathsIII(const vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        int square_cnt = 0;
        int sx = 0;
        int sy = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -1) {
                    continue;
                }
                ++square_cnt;
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(sx, sy, square_cnt, grid, visited);
    }

private:
    int dfs(int sx,
            int sy,
            int square_cnt,
            const vector<vector<int>> &grid,
            vector<vector<bool>> &visited) {
        if (grid[sx][sy] == 2) {
            return square_cnt == 1 ? 1 : 0;
        }
        --square_cnt;
        visited[sx][sy] = true;
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            auto nx = sx + dx[i];
            auto ny = sy + dy[i];
            if (nx < 0 || ny < 0 || nx >= (int) grid.size() || ny >= (int) grid[0].size() || grid[nx][ny] == -1 ||
                visited[nx][ny]) {
                continue;
            }
            ans += dfs(nx, ny, square_cnt, grid, visited);
        }
        ++square_cnt;
        visited[sx][sy] = false;
        return ans;
    }

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0980_H
