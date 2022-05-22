//
// Created by Fengwei Zhang on 5/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0311_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0311_H

#include <vector>

using namespace std;

class Solution {
    // m*k的矩阵和k*n的矩阵相乘，得到m*n的矩阵
    // 优化：跳过矩阵a中为0的位置，最坏的时间复杂度仍然是O(m*n*k)
public:
    vector<vector<int>> multiply(const vector<vector<int>> &a, const vector<vector<int>> &b) {
        const auto m = (int) a.size();
        const auto k = (int) a[0].size();
        const auto n = (int) b[0].size();
        vector<vector<int>> c(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int x = 0; x < k; ++x) {
                if (!a[i][x]) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {  // 累加非零值到目标位置
                    c[i][j] += a[i][x] * b[x][j];
                }
            }
        }
        return c;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0311_H
