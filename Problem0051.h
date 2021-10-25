//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0051_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0051_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0051 {
private:
    void dfs(const int rowIdx,
             const int n,
             bool colUsed[],
             bool dgUsed[],
             bool udgUsed[],
             vector<string> &temp,
             vector<vector<string>> &result
    ) {
        if (rowIdx == n) {
            result.emplace_back(temp);
            return;
        }
        for (int colIdx = 0; colIdx < n; ++colIdx) {
            if (colUsed[colIdx] || dgUsed[rowIdx + colIdx] || udgUsed[rowIdx - colIdx + n]) {
                continue;
            }
            colUsed[colIdx] = dgUsed[rowIdx + colIdx] = udgUsed[rowIdx - colIdx + n] = true;
            temp[rowIdx][colIdx] = 'Q';
            dfs(rowIdx + 1, n, colUsed, dgUsed, udgUsed, temp, result);
            temp[rowIdx][colIdx] = '.';
            colUsed[colIdx] = dgUsed[rowIdx + colIdx] = udgUsed[rowIdx - colIdx + n] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        vector<vector<string>> result;
        bool colUsed[n], dgUsed[2 * n], udgUsed[2 * n];
        memset(colUsed, 0, sizeof colUsed);
        memset(dgUsed, 0, sizeof dgUsed);
        memset(udgUsed, 0, sizeof udgUsed);
        dfs(0, n, colUsed, dgUsed, udgUsed, temp, result);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0051_H
