//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0036_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0036_H

#include <vector>

using namespace std;

class Problem0035 {
private:
    bool isValidSudoku(vector<vector<char>> &board) {
        bool numExisted[10];

        // Test rows
        for (int i = 0; i < 9; ++i) {  // 遍历行
            memset(numExisted, 0, sizeof numExisted);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (numExisted[board[i][j] - '0']) {
                    return false;
                }
                numExisted[board[i][j] - '0'] = true;
            }
        }

        // Test columns
        for (int j = 0; j < 9; ++j) {  // 遍历列
            memset(numExisted, 0, sizeof numExisted);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (numExisted[board[i][j] - '0']) {
                    return false;
                }
                numExisted[board[i][j] - '0'] = true;
            }
        }

        // Test blocks
        for (int k = 0; k < 9; ++k) {  // 遍历每个方块 （从左至右，从上至下）
            memset(numExisted, 0, sizeof numExisted);
            auto startX = k / 3 * 3;  // 方块左上角列号
            auto startY = k % 3 * 3;  // 方块左上角行号
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    if (board[startX + x][startY + y] == '.') {
                        continue;
                    }
                    if (numExisted[board[startX + x][startY + y] - '0']) {
                        return false;
                    }
                    numExisted[board[startX + x][startY + y] - '0'] = true;
                }
            }
        }

        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0036_H
