//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0073_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0073_H

#include <vector>

using namespace std;

class Problem0073 {
    // 经典解法，直接背诵：使用第1行和第1列暂存其它行、列的信息，节约空间
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        const auto m = (int) matrix.size();
        const auto n = (int) matrix[0].size();

        // 使用2个变量记录第1行和第1列有无0
        bool first_row_has_zero = false;
        bool first_col_has_zero = false;
        for (int j = 0; j < n; ++j) {
            if (!matrix[0][j]) {
                first_row_has_zero = true;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (!matrix[i][0]) {
                first_col_has_zero = true;
                break;
            }
        }

        // 使用第1行和第1列记录其他所有列和行有无0
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    break;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }

        // 根据记录操作
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j]) {
                continue;
            }
            for (int i = 0; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }
        if (first_row_has_zero) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (first_col_has_zero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0073_H
