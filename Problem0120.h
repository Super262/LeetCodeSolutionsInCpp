//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0120_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0120_H

#include <cstring>
#include <vector>

using namespace std;

class Solution {
    // f[i][i]：从(0,0)到(i,j)的最小路径和
public:
    int minimumTotal(const vector<vector<int>> &triangle) {
        const auto n = triangle.size();
        int f[2][n];
        memset(f, 0x3f, sizeof f);
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i % 2][0] = triangle[i][0] + f[(i - 1) % 2][0];
            for (int j = 1; j < i; ++j) {
                f[i % 2][j] = triangle[i][j] + min(f[(i - 1) % 2][j - 1], f[(i - 1) % 2][j]);
            }
            f[i % 2][i] = triangle[i][i] + f[(i - 1) % 2][i - 1];
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, f[(n - 1) % 2][i]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0120_H
