//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0074_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0074_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0074 {
private:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        const int m = (int) matrix.size();
        const int n = (int) matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
            return false;
        }
        int left = 0;
        int right = m * n - 1;
        while (left < right) {
            auto mid = left + (right - left + 1) / 2;
            if (matrix[mid / n][mid % n] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return matrix[right / n][right % n] == target;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0074_H
