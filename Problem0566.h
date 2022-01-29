//
// Created by Fengwei Zhang on 1/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0566_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0566_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(const vector<vector<int>> &mat, int r, int c) {
        auto n = (int) mat.size();
        auto m = (int) mat[0].size();
        if (n * m != r * c) {
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < n * m; ++i) {
            res[i / c][i % c] = mat[i / m][i % m];
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0566_H
