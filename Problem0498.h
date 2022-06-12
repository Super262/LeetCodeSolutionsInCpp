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
        if (mat.empty() || mat[0].empty()) {
            return {};
        }
        const auto n = (int) mat.size();
        const auto m = (int) mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);
        for (int i = 0; i < n + m - 1; ++i) {
            if (i % 2) {
                for (auto j = max(0, i - m + 1); j <= min(i, n - 1); ++j) {
                    ans.emplace_back(mat[j][i - j]);
                }
            } else {
                for (auto j = min(i, n - 1); j >= max(0, i - m + 1); --j) {
                    ans.emplace_back(mat[j][i - j]);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0498_H
