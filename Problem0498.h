//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0498_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0498_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(const vector<vector<int>> &mat) {
        vector<int> result;
        if (mat.empty() || mat[0].empty()) {
            return result;
        }
        const auto n = (int) mat.size();
        const auto m = (int) mat[0].size();
        for (int i = 0; i < n + m - 1; ++i) {
            if (i % 2) {
                for (auto j = max(0, i - m + 1); j <= min(i, n - 1); ++j) {
                    result.emplace_back(mat[j][i - j]);
                }
            } else {
                for (auto j = min(i, n - 1); j >= max(0, i - m + 1); --j) {
                    result.emplace_back(mat[j][i - j]);
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0498_H
