//
// Created by Fengwei Zhang on 5/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0348_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0348_H

#include <vector>

using namespace std;

class TicTacToe {
    // 经观察，我们发现，若某方获胜，n个连续的棋子应出现在某行/列/对角线
    // 因此，我们可以统计每行/列/对角线上棋子的个数，来确定当前的获胜方；这可以使空间耗费为O(n)，时间耗费为O(1)
public:
    TicTacToe(int n) {
        this->n = n;
        row_cnt.resize(this->n, 0);
        col_cnt.resize(this->n, 0);
        dg_cnt = 0;
        udg_cnt = 0;
    }

    int move(int row, int col, int player) {
        const int mark = player == 1 ? 1 : -1;
        row_cnt[row] += mark;
        col_cnt[col] += mark;
        if (row == col) {
            dg_cnt += mark;
        }
        if (row + col == n - 1) {
            udg_cnt += mark;
        }
        if (abs(row_cnt[row]) == n || abs(col_cnt[col]) == n || abs(dg_cnt) == n || abs(udg_cnt) == n) {
            return player;
        }
        return 0;
    }

private:
    vector<int> row_cnt;
    vector<int> col_cnt;
    int dg_cnt;
    int udg_cnt;
    int n;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0348_H
