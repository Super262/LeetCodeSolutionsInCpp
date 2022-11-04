//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0052_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0052_H

#include <cstring>

using namespace std;

class Problem0052 {
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
    int dfs(const int row,
            const int n,
            bool col_used[],
            bool dg_used[],
            bool udg_used[]) {
        if (row == n) {
            return 1;
        }
        int result = 0;
        for (int col = 0; col < n; ++col) {
            if (col_used[col] || dg_used[row + col] || udg_used[n + row - col]) {
                continue;
            }
            col_used[col] = dg_used[row + col] = udg_used[n + row - col] = true;
            result += dfs(row + 1, n, col_used, dg_used, udg_used);
            col_used[col] = dg_used[row + col] = udg_used[n + row - col] = false;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0052_H
