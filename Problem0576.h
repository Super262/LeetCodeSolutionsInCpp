//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0576_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0576_H

#include <cstring>

using namespace std;

class Solution {
    // 动态规划：dp[i][j][k]，从(i,j)移动k步后出界的方案数
public:
    int findPaths(int m, int n, int q, int sr, int sc) {
        if (!q) {  // 不要忘记这个特殊情况，否则会发生越界异常！
            return 0;
        }
        const int MOD = 1e9 + 7;
        int dp[m][n][q + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < m; ++i) {
            ++dp[i][0][1];
            ++dp[i][n - 1][1];
        }
        for (int i = 0; i < n; ++i) {
            ++dp[0][i][1];
            ++dp[m - 1][i][1];
        }
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
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
                        dp[x][y][k] = (int) ((dp[x][y][k] + (long long) dp[px][py][k - 1]) % MOD);
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= q; ++i) {
            res = (int) (((long long) res + dp[sr][sc][i]) % MOD);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0576_H
