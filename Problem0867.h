//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0867_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0867_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(const vector<vector<int>> &matrix) {
        auto m = (int) matrix.size();
        auto n = (int) matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0867_H
