//
// Created by Fengwei Zhang on 10/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0308_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0308_H

#include <vector>

using namespace std;

class NumMatrix {
private:
    int n, m;
    vector<vector<int>> fts;

    int lowBit(const int x) {
        return x & -x;
    }

    int prefixSum(const int rIdx, const int cIdx) {
        int result = 0;
        for (int i = cIdx + 1; i > 0; i -= lowBit(i)) {
            result += fts[rIdx][i];
        }
        return result;
    }

    void updateItem(const int rIdx, const int cIdx, const int val) {
        for (int i = cIdx + 1; i <= m; i += lowBit(i)) {
            fts[rIdx][i] += val;
        }
    }

public:
    NumMatrix(const vector<vector<int>> &matrix) {
        n = (int) matrix.size();
        m = (int) matrix[0].size();
        fts = vector<vector<int>>(n, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                updateItem(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        auto dist = val - (prefixSum(row, col) - prefixSum(row, col - 1));
        updateItem(row, col, dist);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (int i = row1; i <= row2; ++i) {
            result += prefixSum(i, col2) - prefixSum(i, col1 - 1);
        }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0308_H
