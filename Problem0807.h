//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0807_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0807_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(const vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        int row_max[m];
        int col_max[n];
        memset(row_max, 0, sizeof row_max);
        memset(col_max, 0, sizeof col_max);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0807_H
