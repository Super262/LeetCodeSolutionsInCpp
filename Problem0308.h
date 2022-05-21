//
// Created by Fengwei Zhang on 10/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0308_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0308_H

#include <vector>

using namespace std;

class NumMatrix {
    // 为矩阵的每行分别开辟树状数组
public:
    NumMatrix(const vector<vector<int>> &matrix) {
        m = (int) matrix.size();
        n = (int) matrix[0].size();
        fts = vector<vector<int>>(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            auto &ft = fts[i];
            const auto &row = matrix[i];
            for (int j = 1; j <= n; ++j) {  // O(n)时间构建每行的树状数组
                ft[j] += row[j - 1];
                auto p = j + lowBit(j);
                if (p > n) {
                    continue;
                }
                ft[p] += ft[j];
            }
        }
    }

    void update(int row, int col, int val) {
        auto dist = val - (prefixSum(row, col + 1) - prefixSum(row, col));
        updateItem(row, col + 1, dist);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (auto i = row1; i <= row2; ++i) {
            ans += prefixSum(i, col2 + 1) - prefixSum(i, col1);
        }
        return ans;
    }

private:
    int m;
    int n;
    vector<vector<int>> fts;

    static int lowBit(const int x) {
        return x & -x;
    }

    int prefixSum(const int ri, const int ci) {
        int ans = 0;
        const auto &ft = fts[ri];
        for (auto i = ci; i > 0; i -= lowBit(i)) {
            ans += ft[i];
        }
        return ans;
    }

    void updateItem(const int ri, const int ci, const int val) {
        auto &ft = fts[ri];
        for (auto i = ci; i <= n; i += lowBit(i)) {
            ft[i] += val;
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0308_H
