//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0304_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0304_H

#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(const vector<vector<int>> &matrix) {
        const int m = (int) matrix.size();
        const int n = (int) matrix[0].size();
        prefix.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(const int &row1, const int &col1, const int &row2, const int &col2) {
        return prefix[row2 + 1][col2 + 1] - prefix[row2 + 1][col1] - prefix[row1][col2 + 1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0304_H
