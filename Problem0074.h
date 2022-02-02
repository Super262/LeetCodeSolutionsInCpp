//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0074_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0074_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 经典解法，直接背诵
public:
    bool searchMatrix(const vector<vector<int>> &matrix, int target) {
        const int m = (int) matrix.size();
        const int n = (int) matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
            return false;
        }
        int l = 0;
        int r = m * n - 1;
        while (l < r) {
            auto mid = l + (r - l + 1) / 2;
            if (matrix[mid / n][mid % n] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return matrix[l / n][l % n] == target;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0074_H
