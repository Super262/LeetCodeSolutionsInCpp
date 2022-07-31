//
// Created by Fengwei Zhang on 2/27/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0778_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0778_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem0778 {
    // 二分，搜索最小答案；给定时长limit，验证能否从起点走到终点
public:
    int swimInWater(const vector<vector<int>> &grid) {
        int l = 0;
        auto r = (int) (grid.size() * grid.size());
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (checkConnectivity(grid, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

    bool checkConnectivity(const vector<vector<int>> &grid, const int limit) {
        if (grid[0][0] > limit) {
            return false;
        }
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        bool visited[m][n];
        queue<pair<int, int>> q;
        memset(visited, 0, sizeof visited);
        visited[0][0] = true;
        q.push({0, 0});
        while (!q.empty()) {
            auto r = q.front();
            q.pop();
            if (r.first == m - 1 && r.second == n - 1) {
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                auto nx = r.first + dx[i];
                auto ny = r.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] > limit || visited[nx][ny]) {
                    continue;
                }
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0778_H
