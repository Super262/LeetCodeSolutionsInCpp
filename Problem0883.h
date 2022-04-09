//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0883_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0883_H

#include <vector>

using namespace std;

class Solution {
    // 结果 = 每列最大值 + 每行最大值 + 非零坐标个数
public:
    int projectionArea(const vector<vector<int>> &grid) {
        int ans = 0;
        const auto n = (int) grid.size();
        for (int i = 0; i < n; ++i) {
            int r = 0;
            int c = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++ans;
                }
                r = max(r, grid[i][j]);
                c = max(c, grid[j][i]);
            }
            ans += r + c;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0883_H
