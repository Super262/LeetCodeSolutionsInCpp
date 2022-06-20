//
// Created by Fengwei Zhang on 1/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0566_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0566_H

#include <vector>

using namespace std;

class Solution {
    // 映射变换，ans[i/c][i%c]=mat[i/n][i%n]，0<=i<=m*n-1
public:
    vector<vector<int>> matrixReshape(const vector<vector<int>> &mat, int r, int c) {
        const auto m = (int) mat.size();
        const auto n = (int) mat[0].size();
        if (m * n != r * c) {
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < m * n; ++i) {
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0566_H
