//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0073_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0073_H

#include <vector>

using namespace std;

class Problem0073 {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        const int n = (int) matrix.size();
        const int m = (int) matrix[0].size();
        // 使用2个变量记录第1行和第1列有无0
        bool firstRowHasZero = false;
        bool firstColHasZero = false;
        for (int j = 0; j < m; ++j) {
            if (!matrix[0][j]) {
                firstRowHasZero = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!matrix[i][0]) {
                firstColHasZero = true;
            }
        }
        // 使用第1行和第1列记录其他所有列和行有无0
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    break;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }
        // 根据记录操作
        for (int i = 1; i < n; ++i) {
            if (matrix[i][0]) {
                continue;
            }
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < m; ++j) {
            if (matrix[0][j]) {
                continue;
            }
            for (int i = 0; i < n; ++i) {
                matrix[i][j] = 0;
            }
        }
        if (firstRowHasZero) {
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (firstColHasZero) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0073_H
