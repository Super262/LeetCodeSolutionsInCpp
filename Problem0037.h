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
    static const int N = 9;
    bool colUsed[N][N];
    bool rowUsed[N][N];
    bool blockUsed[N][N];

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
            if (rowUsed[x][d] || colUsed[y][d] || blockUsed[x / 3 * 3 + y / 3][d]) {
                continue;
            }
            board[x][y] = (char) ('1' + d);
            rowUsed[x][d] = colUsed[y][d] = blockUsed[x / 3 * 3 + y / 3][d] = true;
            if (dfs(x, y + 1, board)) {
                return true;
            }
            board[x][y] = '.';
            rowUsed[x][d] = colUsed[y][d] = blockUsed[x / 3 * 3 + y / 3][d] = false;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board) {
        memset(colUsed, 0, sizeof colUsed);
        memset(rowUsed, 0, sizeof rowUsed);
        memset(blockUsed, 0, sizeof blockUsed);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                auto digit = board[i][j] - '1';
                rowUsed[i][digit] = true;
                colUsed[j][digit] = true;
                blockUsed[i / 3 * 3 + j / 3][digit] = true;
            }
        }
        dfs(0, 0, board);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0037_H
