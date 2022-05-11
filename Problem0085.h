//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0085_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0085_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 单调栈经典应用
public:
    int maximalRectangle(const vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        const int m = (int) matrix.size();
        const int n = (int) matrix[0].size();
        int heights[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                heights[i][j] = 0;
                if (matrix[i][j] == '0') {
                    continue;
                }
                heights[i][j] = 1;
                if (i > 0) {
                    heights[i][j] += heights[i - 1][j];
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            result = max(result, largestRectangleArea(heights[i], n));
        }
        return result;
    }

private:
    int largestRectangleArea(const int heights[], const int n) {
        vector<int> stk;
        stk.reserve(n);

        // 求左边界
        int left_bro[n];
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                left_bro[i] = -1;
            } else {
                left_bro[i] = stk.back();
            }
            stk.emplace_back(i);
        }

        // 清空栈！！
        stk.clear();
        stk.reserve(n);

        // 求右边界
        int right_bro[n];
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                right_bro[i] = n;
            } else {
                right_bro[i] = stk.back();
            }
            stk.emplace_back(i);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, (right_bro[i] - left_bro[i] - 1) * heights[i]);
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0085_H
