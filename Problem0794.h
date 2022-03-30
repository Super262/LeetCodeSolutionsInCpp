//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0794_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0794_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool validTicTacToe(const vector<string> &board) {
        auto wx = hasWon(board, 'X');
        auto wo = hasWon(board, 'O');
        if (wx && wo) {  // 不可能同时获胜
            return false;
        }
        auto cx = countChar(board, 'X');
        auto co = countChar(board, 'O');
        if (wx && cx != co + 1) {  // 先手获胜，'X'应多于'O'
            return false;
        }
        if (wo && co != cx) {  // 后手获胜，'X'应等于'O'
            return false;
        }
        if (cx != co && cx != co + 1) {  // 'X'的数量应大于或等于'O'的数量
            return false;
        }
        return true;
    }

private:
    int countChar(const vector<string> &board, char t) {  // 统计t的个数
        int ans = 0;
        for (const auto &row: board) {
            for (const auto &ch: row) {
                if (ch != t) {
                    continue;
                }
                ++ans;
            }
        }
        return ans;
    }

    bool hasWon(const vector<string> &board, char t) {  // 判断t是否获胜
        for (int i = 0; i < 3; ++i) {  // 整行/列
            if (board[i][0] == t && board[i][1] == t && board[i][2] == t) {
                return true;
            }
            if (board[0][i] == t && board[1][i] == t && board[2][i] == t) {
                return true;
            }
        }
        // 两条对角线
        if (board[0][0] == t && board[1][1] == t && board[2][2] == t) {
            return true;
        }
        if (board[0][2] == t && board[1][1] == t && board[2][0] == t) {
            return true;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0794_H
