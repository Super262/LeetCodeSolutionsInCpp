//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0576_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0576_H

#include <cstring>

using namespace std;

class Solution {
    // 动态规划：f[i][j][k]，从(i,j)移动k步后出界的方案数
public:
    int findPaths(int m, int n, int q, int sr, int sc) {
        if (!q) {  // 不要忘记这个特殊情况，否则会发生越界异常！
            return 0;
        }
        int f[m][n][q + 1];
        memset(f, 0, sizeof f);
        for (int i = 0; i < m; ++i) {  // 初始化左、右两侧边界点的方案数
            ++f[i][0][1];
            ++f[i][n - 1][1];
        }
        for (int i = 0; i < n; ++i) {  // 初始化上、下两侧边界点的方案数
            ++f[0][i][1];
            ++f[m - 1][i][1];
        }
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        const int MOD = 1e9 + 7;
        for (int k = 1; k <= q; ++k) {  // 在外层，从小到大枚举步数
            // 从外到内依次枚举(i,j)
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    for (int u = 0; u < 4; ++u) {
                        auto px = x + dx[u];
                        auto py = y + dy[u];
                        if (px < 0 || py < 0 || px >= m || py >= n) {
                            continue;
                        }
                        f[x][y][k] = (int) ((f[x][y][k] + (long long) f[px][py][k - 1]) % MOD);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= q; ++i) {
            ans = (int) (((long long) ans + f[sr][sc][i]) % MOD);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0576_H
