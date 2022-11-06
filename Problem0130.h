//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0130_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0130_H

#include <vector>
#include <queue>

using namespace std;

class Problem0130 {
    // 逆向思维：从边界寻找没有被X包围的O
public:
    void solve(vector<vector<char>> &board) {
        const int n = (int) board.size();
        const int m = (int) board[0].size();
        for (int i = 0; i < m; ++i) {  // 上下边界
            if (board[0][i] == 'O') {
                bfs(board, 0, i);
            }
            if (board[n - 1][i] == 'O') {
                bfs(board, n - 1, i);
            }
        }
        for (int i = 0; i < n; ++i) {  // 左右边界
            if (board[i][0] == 'O') {
                bfs(board, i, 0);
            }
            if (board[i][m - 1] == 'O') {
                bfs(board, i, m - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != 'O') {
                    continue;
                }
                board[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != 'Y') {
                    continue;
                }
                board[i][j] = 'O';
            }
        }
    }

private:
    void bfs(vector<vector<char>> &board, const int x, const int y) {
        const int n = (int) board.size();
        const int m = (int) board[0].size();
        queue<pair<int, int>> q;
        q.emplace(pair<int, int>(x, y));
        board[x][y] = 'Y';  // 使用新标记
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            auto rx = root.first;
            auto ry = root.second;
            for (int i = 0; i < 4; ++i) {
                auto nx = rx + dx[i];
                auto ny = ry + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (board[nx][ny] != 'O') {
                    continue;
                }
                q.emplace(pair<int, int>(nx, ny));
                board[nx][ny] = 'Y';
            }
        }
    }

    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0130_H
