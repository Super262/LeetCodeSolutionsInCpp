//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0419_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0419_H

#include <vector>

using namespace std;

class Solution {
    // 要求O(1)额外空间：只统计左上角位置
    // 背诵代码！
public:
    int countBattleships(const vector<vector<char>> &board) {
        int res = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (i > 0 && board[i - 1][j] == 'X') {  // 是战舰部分，但不是左上角
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {  // 是战舰部分，但不是左上角
                    continue;
                }
                if (board[i][j] == 'X') {
                    ++res;
                }
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0419_H
