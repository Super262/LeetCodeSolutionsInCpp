//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0037_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0037_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0037 {
public:
    void solveSudoku(vector<vector<char>> &board) {
        memset(col_used, 0, sizeof col_used);
        memset(row_used, 0, sizeof row_used);
        memset(block_used, 0, sizeof block_used);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                auto digit = board[i][j] - '1';
                row_used[i][digit] = true;
                col_used[j][digit] = true;
                block_used[i / 3 * 3 + j / 3][digit] = true;
            }
        }
        dfs(0, 0, board);
    }

private:
    static const int N = 9;
    bool col_used[N][N];
    bool row_used[N][N];
    bool block_used[N][N];

    bool dfs(int x, int y, vector<vector<char>> &board) {
        if (y == N) {
            ++x;
            y = 0;
        }
        if (x == N) {
            return true;
        }
        if (board[x][y] != '.') {
            return dfs(x, y + 1, board);
        }
        for (int d = 0; d < 9; ++d) {
            if (row_used[x][d] || col_used[y][d] || block_used[x / 3 * 3 + y / 3][d]) {
                continue;
            }
            board[x][y] = (char) ('1' + d);
            row_used[x][d] = col_used[y][d] = block_used[x / 3 * 3 + y / 3][d] = true;
            if (dfs(x, y + 1, board)) {
                return true;
            }
            board[x][y] = '.';
            row_used[x][d] = col_used[y][d] = block_used[x / 3 * 3 + y / 3][d] = false;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0037_H
