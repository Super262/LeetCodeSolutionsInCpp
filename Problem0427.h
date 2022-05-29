//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0427_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0427_H

#include <vector>
#include "quad_node.h"

using namespace std;

class Solution {
    // 2维前缀和+先序遍历：先判断根结点是否能成为叶（sum为0或m*n）；若根不能为叶，生成4个子节点
public:
    Node *construct(const vector<vector<int>> &grid) {
        vector<vector<int>> prefix = getPrefix(grid);
        return dfs(1, 1, (int) grid.size(), (int) grid[0].size(), prefix);
    }

private:
    Node *dfs(int x1, int y1, int x2, int y2, const vector<vector<int>> &prefix) {
        auto m = x2 - x1 + 1;
        auto n = y2 - y1 + 1;
        auto sum = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
        if (sum == 0 || sum == m * n) {
            return new Node(sum > 0, true);
        }
        auto top_left = dfs(x1, y1, x1 + m / 2 - 1, y1 + n / 2 - 1, prefix);
        auto top_right = dfs(x1, y1 + n / 2, x1 + m / 2 - 1, y2, prefix);
        auto bottom_left = dfs(x1 + m / 2, y1, x2, y1 + n / 2 - 1, prefix);
        auto bottom_right = dfs(x1 + m / 2, y1 + n / 2, x2, y2, prefix);
        return new Node(false, false, top_left, top_right, bottom_left, bottom_right);
    }

    vector<vector<int>> getPrefix(const vector<vector<int>> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                res[i][j] = res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0427_H
