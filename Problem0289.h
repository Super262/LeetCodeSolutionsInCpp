//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0289_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0289_H

#include<vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        // 利用整数的其它2进制位记录未来状态，最后1位记录当前状态
        // https://www.acwing.com/solution/content/291/
        const int m = (int) board.size();
        if (m == 0) {
            return;
        }
        const int n = (int) board[0].size();
        if (n == 0) {
            return;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int livingOnes = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        auto ni = i + di;
                        auto nj = j + dj;
                        if (ni == i && nj == j) {  // 不忘记排除原点！！
                            continue;
                        }
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                            continue;
                        }
                        livingOnes += (board[ni][nj] & 1);  // 最后1位表示状态
                    }
                }
                if ((board[i][j] & 1) == 1) {
                    if (livingOnes < 2 || livingOnes > 3) {
                        board[i][j] = 1;  // 未来是0，当前是1：01
                    } else {
                        board[i][j] = 3;  // 未来是1，当前是1：11
                    }
                } else {
                    if (livingOnes == 3) {
                        board[i][j] = 2;  // 未来是1，当前是0：10
                    } else {
                        board[i][j] = 0;  // 未来是0，当前是0：00
                    }
                }
            }
        }
        // 恢复网格
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0289_H
