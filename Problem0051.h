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
        vector<string> temp(n, string(n, '.'));
        vector<vector<string>> result;
        bool col_used[n], dg_used[2 * n], udg_used[2 * n];
        memset(col_used, 0, sizeof col_used);
        memset(dg_used, 0, sizeof dg_used);
        memset(udg_used, 0, sizeof udg_used);
        dfs(0, n, col_used, dg_used, udg_used, temp, result);
        return result;
    }

private:
    void dfs(const int row_idx,
             const int n,
             bool col_used[],
             bool dg_used[],
             bool udg_used[],
             vector<string> &temp,
             vector<vector<string>> &result) {
        if (row_idx == n) {
            result.emplace_back(temp);
            return;
        }
        for (int colIdx = 0; colIdx < n; ++colIdx) {
            if (col_used[colIdx] || dg_used[row_idx + colIdx] || udg_used[row_idx - colIdx + n]) {
                continue;
            }
            col_used[colIdx] = dg_used[row_idx + colIdx] = udg_used[row_idx - colIdx + n] = true;
            temp[row_idx][colIdx] = 'Q';
            dfs(row_idx + 1, n, col_used, dg_used, udg_used, temp, result);
            temp[row_idx][colIdx] = '.';
            col_used[colIdx] = dg_used[row_idx + colIdx] = udg_used[row_idx - colIdx + n] = false;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0051_H
