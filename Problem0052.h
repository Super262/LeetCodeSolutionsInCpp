//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0052_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0052_H

#include <cstring>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        bool col_used[n];
        bool dg_used[2 * n];
        bool udg_used[2 * n];
        memset(col_used, 0, sizeof col_used);
        memset(dg_used, 0, sizeof dg_used);
        memset(udg_used, 0, sizeof udg_used);
        return dfs(0, n, col_used, dg_used, udg_used);
    }

private:
    int dfs(const int r_idx,
            const int n,
            bool col_used[],
            bool dg_used[],
            bool udg_used[]) {
        if (r_idx == n) {
            return 1;
        }
        int result = 0;
        for (int colIdx = 0; colIdx < n; ++colIdx) {
            if (col_used[colIdx] || dg_used[r_idx + colIdx] || udg_used[n + r_idx - colIdx]) {
                continue;
            }
            col_used[colIdx] = dg_used[r_idx + colIdx] = udg_used[n + r_idx - colIdx] = true;
            result += dfs(r_idx + 1, n, col_used, dg_used, udg_used);
            col_used[colIdx] = dg_used[r_idx + colIdx] = udg_used[n + r_idx - colIdx] = false;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0052_H
