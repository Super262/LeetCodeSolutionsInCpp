//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0240_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0240_H

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(const vector<vector<int>> &matrix, const int &target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        const int n = (int) matrix.size();
        const int m = (int) matrix[0].size();
        int i = 0;
        int j = m - 1;
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
