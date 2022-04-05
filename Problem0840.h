//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0840_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0840_H

#include <vector>

using namespace std;

class Solution {
    // 枚举3*3网格中元素；网格的总和是 45，因为网格必须是 1 到 9 不同的数字
    // 每一列和行加起来必须是 15，乘以 3 则是网格的总和；对角线的和也必须是 15，题目中说了对角线与列，行的和相同
    // 共有4条线穿过网格中心，这四条线加起来等于 60，而整个网格加起来为 45；中心等于 (60 - 45) / 3 = 5
public:
    int numMagicSquaresInside(const vector<vector<int>> &grid) {
        int ans = 0;
        for (int i = 0; i + 3 <= grid.size(); ++i) {
            for (int j = 0; j + 3 <= grid[0].size(); ++j) {
                if (isMagic(grid, i, j)) {
                    ++ans;
                }
            }
        }
        return ans;
    }

private:
    bool isMagic(const vector<vector<int>> &grid, int sx, int sy) {
        if (grid[sx + 1][sy + 1] != 5) {
            return false;
        }
        // 判断各个数字是否为1～9且不重复
        int existed = 0;
        for (auto i = sx; i < sx + 3; ++i) {
            for (auto j = sy; j < sy + 3; ++j) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || ((existed >> (grid[i][j] - 1)) & 1)) {
                    return false;
                }
                existed |= 1 << (grid[i][j] - 1);
            }
        }
        if (existed != (1 << 9) - 1) {
            return false;
        }
        // 判断各行、各列的和相等
        auto s = grid[sx][sy] + grid[sx][sy + 1] + grid[sx][sy + 2];
        for (int i = 0; i < 3; ++i) {
            if (grid[sx + i][sy] + grid[sx + i][sy + 1] + grid[sx + i][sy + 2] != s) {
                return false;
            }
            if (grid[sx][sy + i] + grid[sx + 1][sy + i] + grid[sx + 2][sy + i] != s) {
                return false;
            }
        }
        // 判断两条对角线相等
        if (grid[sx][sy] + grid[sx + 1][sy + 1] + grid[sx + 2][sy + 2] != s) {
            return false;
        }
        if (grid[sx + 2][sy] + grid[sx + 1][sy + 1] + grid[sx][sy + 2] != s) {
            return false;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0840_H
