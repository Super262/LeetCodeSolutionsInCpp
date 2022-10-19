//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0999_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0999_H

#include <vector>

using namespace std;

class Problem0999 {
    // 直接模拟，先找到Rook的位置，再分别尝试向4个方向移动
public:
    int numRookCaptures(const vector<vector<char>> &board) {
        const auto m = (int) board.size();
        const auto n = (int) board[0].size();
        int sx = -1;
        int sy = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'R') {
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            auto x = sx;
            auto y = sy;
            while (true) {
                x += dx[i];
                y += dy[i];
                if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == 'B') {
                    break;
                }
                if (board[x][y] == 'p') {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0999_H
