//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0329_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0329_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 转化点和点之间的关系为DAG，拓扑排序：若a、b邻接且a<b，DAG中包含边(b,a)
public:
    int longestIncreasingPath(const vector<vector<int>> &matrix) {
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};
        const auto m = (int) matrix.size();
        const auto n = (int) matrix[0].size();
        queue<pair<int, int>> q;
        int degree[m][n];
        memset(degree, 0, sizeof degree);
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                for (int i = 0; i < 4; ++i) {
                    auto nx = x + dx[i];
                    auto ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] <= matrix[x][y]) {
                        continue;
                    }
                    ++degree[x][y];
                }
                if (!degree[x][y]) {
                    q.emplace(x, y);
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (auto i = (int) q.size(); i > 0; --i) {
                auto t = q.front();
                q.pop();
                auto x = t.first;
                auto y = t.second;
                for (int j = 0; j < 4; ++j) {
                    auto nx = x + dx[j];
                    auto ny = y + dy[j];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] >= matrix[x][y]) {
                        continue;
                    }
                    --degree[nx][ny];
                    if (!degree[nx][ny]) {
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        return ans;
    }
};

/*
class Solution {
    // DFS，记忆化搜索严格递增序列，类似AcWing 901
public:
    int longestIncreasingPath(const vector<vector<int>> &matrix) {
        const int m = (int) matrix.size();
        const int n = (int) matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n, -1));
        int ans = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j, matrix, f));
            }
        }
        return ans;
    }

private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    int dfs(const int &x,
            const int &y,
            const vector<vector<int>> &matrix,
            vector<vector<int>> &f) {
        if (f[x][y] != -1) {
            return f[x][y];
        }
        f[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size() || matrix[nx][ny] <= matrix[x][y]) {
                continue;
            }
            f[x][y] = max(f[x][y], dfs(nx, ny, matrix, f) + 1);
        }
        return f[x][y];
    }
};
*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0329_H
