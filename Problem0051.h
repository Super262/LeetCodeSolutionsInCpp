//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0051_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0051_H

#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n, string(n, '.'));
        vector<vector<string>> ans;
        bool col_used[n], dg_used[2 * n], udg_used[2 * n];
        memset(col_used, 0, sizeof col_used);
        memset(dg_used, 0, sizeof dg_used);
        memset(udg_used, 0, sizeof udg_used);
        dfs(0, n, col_used, dg_used, udg_used, cur, ans);
        return ans;
    }

private:
    void dfs(const int row,
             const int n,
             bool col_used[],
             bool dg_used[],
             bool udg_used[],
             vector<string> &cur,
             vector<vector<string>> &ans) {
        if (row == n) {
            ans.emplace_back(cur);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (col_used[col] || dg_used[row + col] || udg_used[row - col + n]) {
                continue;
            }
            col_used[col] = dg_used[row + col] = udg_used[row - col + n] = true;
            cur[row][col] = 'Q';
            dfs(row + 1, n, col_used, dg_used, udg_used, cur, ans);
            cur[row][col] = '.';
            col_used[col] = dg_used[row + col] = udg_used[row - col + n] = false;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0051_H
