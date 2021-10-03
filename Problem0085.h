//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0085_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0085_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Problem0085 {
private:
    int largestRectangleArea(const int heights[], const int n) {
        vector<int> stk;
        int leftH[n];
        int rightH[n];

        // 求左边界
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                leftH[i] = -1;
            } else {
                leftH[i] = stk.back();
            }
            stk.emplace_back(i);
        }

        // 清空栈！！
        stk.clear();

        // 求右边界
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                rightH[i] = n;
            } else {
                rightH[i] = stk.back();
            }
            stk.emplace_back(i);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, (rightH[i] - leftH[i] - 1) * heights[i]);
        }

        return result;
    }

    int maximalRectangle(vector<vector<char>> &matrix) {
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
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0085_H
