//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0417_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0417_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        const int m = (int) heights.size();
        const int n = (int) heights[0].size();
        vector<vector<int>> st(m, vector<int>(n, 0));  // 11：从两个方向可达；01：从太平洋可达；10：从大西洋可达
        for (int i = 0; i < m; ++i) {  // 注意排除同一方向的重复搜索！
            dfs(i, 0, 1, heights, st);
            dfs(i, n - 1, 2, heights, st);
        }
        for (int i = 1; i < n; ++i) {  // 注意排除同一方向的重复搜索！
            dfs(0, i, 1, heights, st);
            dfs(m - 1, i - 1, 2, heights, st);
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (st[i][j] != 3) {
                    continue;
                }
                res.push_back({i, j});
            }
        }
        return res;
    }

private:
    void dfs(int x, int y, int t, const vector<vector<int>> &heights, vector<vector<int>> &st) {
        st[x][y] |= t;
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; ++i) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if (nx < 0 || nx >= heights.size() || ny < 0 || ny >= heights[0].size() ||
                heights[nx][ny] < heights[x][y] || st[nx][ny] & t) {
                continue;
            }
            dfs(nx, ny, t, heights, st);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0417_H
