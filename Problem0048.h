//
// Created by Fengwei Zhang on 10/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0048_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0048_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵
public:
    void rotate(vector<vector<int>> &matrix) {  // 先沿对角线翻转，再沿中轴翻转
        const int n = (int) matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int l = 0, r = n - 1; l < r; ++l, --r) {
                swap(matrix[i][l], matrix[i][r]);
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0048_H
