//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0221_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0221_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // f[i][j]是以(i, j)为右下角的、全1矩形的最小边长
    // 细节：f[i][j]既转移自f[i-1][j]、f[i][j-1]，也转移自f[i-1][j-1]，不要忽略这点
public:
    int maximalSquare(const vector<vector<char>> &matrix) {
        const auto m = (int) matrix.size();
        const auto n = (int) matrix[0].size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '0') {
                    continue;
                }
                f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
                ans = max(ans, f[i][j] * f[i][j]);  // 计算面积
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0221_H
