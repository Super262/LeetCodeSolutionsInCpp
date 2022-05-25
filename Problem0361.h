//
// Created by Fengwei Zhang on 5/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0361_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0361_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 暴力算法：从上到下、从左到右遍历，枚举所有空白点(i,j)，遍历它所在的行和列，统计墙之前的敌人的数量
    // 我们为暴力算法添加些优化策略：统计在(i,j)放置炸弹的情况时，我们可以利用(i-1,j)和(i,j-1)的信息
    // 设在(i,j)放置炸弹后，可消除该行row_hits[i][j]个敌人，可消除该列col_hits[i][j]个敌人
    // 若(i-1,j)为墙，我们应从第i行重新统计本列的敌人数量col_hits[j]；否则，col_hits[i][j]=col_hits[i-1][j]
    // 若(i,j-1)为墙，我们应从第j列重新统计本行的敌人数量row_hits[i]；否则，row_hits[i][j]=row_hits[i][j-1]
    // i或j为0时，我们要初始化当前行、列的敌人数量
public:
    int maxKilledEnemies(const vector<vector<char>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        int ans = 0;
        int col_hits[n];
        int row_hits = 0;
        memset(col_hits, 0, sizeof col_hits);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!j || grid[i][j - 1] == 'W') {  // 重置row_hits
                    row_hits = 0;
                    for (auto k = j; k < n; ++k) {
                        if (grid[i][k] == 'W') {
                            break;
                        }
                        if (grid[i][k] == 'E') {
                            ++row_hits;
                        }
                    }
                }
                if (!i || grid[i - 1][j] == 'W') {  // 重置col_hits[j]
                    col_hits[j] = 0;
                    for (auto k = i; k < m; ++k) {
                        if (grid[k][j] == 'W') {
                            break;
                        }
                        if (grid[k][j] == 'E') {
                            ++col_hits[j];
                        }
                    }
                }
                if (grid[i][j] == '0') {
                    ans = max(ans, row_hits + col_hits[j]);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0361_H
