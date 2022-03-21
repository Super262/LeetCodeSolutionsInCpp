//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0240_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0240_H

#include <vector>

using namespace std;

class Solution {
    // 从右上角开始遍历
public:
    bool searchMatrix(const vector<vector<int>> &matrix, const int &target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        const auto n = (int) matrix.size();
        const auto m = (int) matrix[0].size();
        int i = 0;
        auto j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0240_H
