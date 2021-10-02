//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0052_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0052_H

#include <cstring>

using namespace std;

class Problem0052 {
public:
    int dfs(const int rowIdx,
            const int n,
            bool colUsed[],
            bool dgUsed[],
            bool udgUsed[]) {
        if (rowIdx == n) {
            return 1;
        }
        int result = 0;
        for (int colIdx = 0; colIdx < n; ++colIdx) {
            if (colUsed[colIdx] || dgUsed[rowIdx + colIdx] || udgUsed[n + rowIdx - colIdx]) {
                continue;
            }
            colUsed[colIdx] = dgUsed[rowIdx + colIdx] = udgUsed[n + rowIdx - colIdx] = true;
            result += dfs(rowIdx + 1, n, colUsed, dgUsed, udgUsed);
            colUsed[colIdx] = dgUsed[rowIdx + colIdx] = udgUsed[n + rowIdx - colIdx] = false;
        }
        return result;
    }

    int totalNQueens(int n) {
        bool colUsed[n];
        bool dgUsed[2 * n];
        bool udgUsed[2 * n];
        memset(colUsed, 0, sizeof colUsed);
        memset(dgUsed, 0, sizeof dgUsed);
        memset(udgUsed, 0, sizeof udgUsed);
        return dfs(0, n, colUsed, dgUsed, udgUsed);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0052_H
