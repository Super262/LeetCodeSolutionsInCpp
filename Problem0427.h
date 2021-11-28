//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0427_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0427_H

#include <vector>

using namespace std;


class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node *construct(const vector<vector<int>> &grid) {
        vector<vector<int>> prefix = getPrefix(grid);
        return dfs(1, 1, (int) grid.size(), (int) grid[0].size(), prefix);
    }

private:
    Node *dfs(int x1, int y1, int x2, int y2, const vector<vector<int>> &prefix) {
        int m = x2 - x1 + 1;
        int n = y2 - y1 + 1;
        int sum = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
        if (sum == 0 || sum == m * n) {
            return new Node(sum > 0, true);
        }
        auto topLeft = dfs(x1, y1, x1 + m / 2 - 1, y1 + n / 2 - 1, prefix);
        auto topRight = dfs(x1, y1 + n / 2, x1 + m / 2 - 1, y2, prefix);
        auto bottomLeft = dfs(x1 + m / 2, y1, x2, y1 + n / 2 - 1, prefix);
        auto bottomRight = dfs(x1 + m / 2, y1 + n / 2, x2, y2, prefix);
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    vector<vector<int>> getPrefix(const vector<vector<int>> &grid) {
        const int m = (int) grid.size();
        const int n = (int) grid[0].size();
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
