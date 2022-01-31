//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0036_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0036_H

#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(const vector<vector<char>> &board) {
        bool existed[10];

        // Test rows
        for (int i = 0; i < 9; ++i) {  // 遍历行
            memset(existed, 0, sizeof existed);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (existed[board[i][j] - '0']) {
                    return false;
                }
                existed[board[i][j] - '0'] = true;
            }
        }

        // Test columns
        for (int j = 0; j < 9; ++j) {  // 遍历列
            memset(existed, 0, sizeof existed);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (existed[board[i][j] - '0']) {
                    return false;
                }
                existed[board[i][j] - '0'] = true;
            }
        }

        // Test blocks
        for (int k = 0; k < 9; ++k) {  // 遍历每个方块 （从左至右，从上至下）
            memset(existed, 0, sizeof existed);
            auto sx = k / 3 * 3;  // 方块左上角列号
            auto sy = k % 3 * 3;  // 方块左上角行号
            for (int dx = 0; dx < 3; ++dx) {
                for (int dy = 0; dy < 3; ++dy) {
                    if (board[sx + dx][sy + dy] == '.') {
                        continue;
                    }
                    if (existed[board[sx + dx][sy + dy] - '0']) {
                        return false;
                    }
                    existed[board[sx + dx][sy + dy] - '0'] = true;
                }
            }
        }

        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0036_H
