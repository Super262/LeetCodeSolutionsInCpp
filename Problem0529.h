//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0529_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0529_H

#include <vector>

using namespace std;

class Solution {
    // 设当前被点击的坐标是(x,y)；若board[x][y]='M'，更新board[x][y]为'X'，直接返回
    // 若board[x][y]='E'，我们仍需确定(x,y)周围8个点是否含雷；若(x,y)周围8个点中，有k个为雷（1<=k<=8），设置board[x][y]='k'，停止搜索
    // 若(x,y)周围8个点不含雷，设置board[x][y]='B'，继续DFS搜索每个邻点
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, const vector<int> &click) {
        auto x = click[0];
        auto y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        }
        if (board[x][y] == 'E') {
            dfs(x, y, board);
        }
        return board;
    }

private:
    void dfs(int x, int y, vector<vector<char>> &board) {  // 深度搜索，探索空地
        const auto n = (int) board.size();
        const auto m = (int) board[0].size();
        int mines_cnt = 0;
        for (int i = max(0, x - 1); i <= min(x + 1, n - 1); ++i) {
            for (int j = max(0, y - 1); j <= min(y + 1, m - 1); ++j) {
                if (i == x && j == y) {
                    continue;
                }
                if (board[i][j] == 'M') {
                    ++mines_cnt;
                }
            }
        }
        if (mines_cnt > 0) {
            board[x][y] = (char) ('0' + mines_cnt);
            return;
        }
        board[x][y] = 'B';
        for (int i = max(0, x - 1); i <= min(x + 1, n - 1); ++i) {  // 临近无雷，继续探索
            for (int j = max(0, y - 1); j <= min(y + 1, m - 1); ++j) {
                if (i == x && j == y) {
                    continue;
                }
                if (board[i][j] == 'E') {
                    dfs(i, j, board);
                }
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0529_H
