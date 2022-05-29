//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0419_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0419_H

#include <vector>

using namespace std;

class Solution {
    // 只统计战舰的起点位置，跳过其他部分，实现O(1)空间
public:
    int countBattleships(const vector<vector<char>> &board) {
        int ans = 0;
        for (int i = 0; i < (int) board.size(); ++i) {
            for (int j = 0; j < (int) board[0].size(); ++j) {
                if (i > 0 && board[i - 1][j] == 'X') {  // 是战舰部分，但不是起点
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {  // 是战舰部分，但不是起点
                    continue;
                }
                if (board[i][j] == 'X') {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0419_H
