//
// Created by Fengwei Zhang on 10/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0048_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0048_H

#include <vector>

using namespace std;

class Problem0048 {
public:
    void rotate(vector<vector<int>> &matrix) {  // 先沿对角线翻转，再沿中轴翻转
        const int n = (int) matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0, k = n - 1; j < k; ++j, --k) {
                swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0048_H
