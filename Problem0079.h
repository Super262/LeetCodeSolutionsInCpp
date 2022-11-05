//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0079_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0079_H

#include <vector>
#include <string>

using namespace std;

class Problem0079 {
public:
    bool exist(vector<vector<char>> &board, const string &word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (word[0] != board[i][j]) {
                    continue;
                }
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, const string &word, const int x, const int y, const int idx) {
        if (idx == word.size() - 1) {
            return true;
        }
        auto ch = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; ++i) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) {
                continue;
            }
            if (board[nx][ny] != word[idx + 1]) {
                continue;
            }
            if (dfs(board, word, nx, ny, idx + 1)) {
                board[x][y] = ch;
                return true;
            }
        }
        board[x][y] = ch;
        return false;
    }

    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0079_H
