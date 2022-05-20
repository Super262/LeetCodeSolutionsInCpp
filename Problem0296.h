//
// Created by Fengwei Zhang on 5/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0296_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0296_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 重要性质：距其它点距离之和最小的点位于所有点坐标的中位数位置（掌握证明）
    // 由于距离度量使用曼哈顿距离，我们可以独立处理横、纵方向的坐标序列
public:
    int minTotalDistance(const vector<vector<int>> &grid) {
        auto rows = collectRows(grid);
        auto cols = collectCols(grid);
        auto x = rows[rows.size() / 2];
        auto y = cols[cols.size() / 2];
        return minDistance1D(rows, x) + minDistance1D(cols, y);
    }

private:
    vector<int> collectRows(const vector<vector<int>> &grid) {
        vector<int> rows;
        rows.reserve(grid.size());
        for (int x = 0; x < (int) grid.size(); ++x) {  // 从小到大遍历横坐标
            for (int y = 0; y < (int) grid[0].size(); ++y) {
                if (grid[x][y]) {
                    rows.emplace_back(x);
                }
            }
        }
        return rows;
    }

    vector<int> collectCols(const vector<vector<int>> &grid) {
        vector<int> cols;
        cols.reserve(grid[0].size());
        for (int y = 0; y < (int) grid[0].size(); ++y) {  // 从小到大遍历纵坐标
            for (int x = 0; x < (int) grid.size(); ++x) {
                if (grid[x][y]) {
                    cols.emplace_back(y);
                }
            }
        }
        return cols;
    }

    int minDistance1D(const vector<int> &points, int origin) {
        int ans = 0;
        for (const auto &p: points) {
            ans += abs(origin - p);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0296_H
