//
// Created by Fengwei Zhang on 7/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0750_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0750_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0750 {
    // 朴素解法（时间复杂度为O(R*C^2)）：计算每增加1行，角矩形增加了多少；设当前行为i，counter[c1][c2]记录前面0～i-1行在列c1、c2处为"1"的行数
    // 当我们处理第i行时，若第i行的c1、c2列均为"1"，我们添加counter[c1][c2]到答案，并执行counter[c1][c2]++
    // 以后注意理解LeetCode的题解的高效做法
public:
    int countCornerRectangles(const vector<vector<int>> &grid) {  // 朴素解法
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        int counter[n][n];
        memset(counter, 0, sizeof counter);
        int ans = 0;
        for (int r = 0; r < m; ++r) {
            for (int c1 = 0; c1 < n; ++c1) {
                if (!grid[r][c1]) {
                    continue;
                }
                for (int c2 = c1 + 1; c2 < n; ++c2) {
                    if (!grid[r][c2]) {
                        continue;
                    }
                    ans += counter[c1][c2];
                    ++counter[c1][c2];
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0750_H
