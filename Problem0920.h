//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0920_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0920_H

#include <cstring>

class Solution {
    // f[i][j]：前i首歌、共j种的方案数
    // 若第i首歌从未被选择，f[i][j] = f[i - 1][j - 1] * (n - j + 1)
    // 若第i首歌曾经被选择过，第i首歌应是最早被选择的(j - k)首歌之一，f[i][j] = f[i - 1][j] * max(j - k, 0)
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int f[goal + 1][n + 1];
        const int M = 1e9 + 7;
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= goal && j <= n; ++j) {
                f[i][j] = (int) ((long long) f[i - 1][j - 1] * (n - j + 1) % M);
                if (j - k > 0) {
                    f[i][j] = (int) ((f[i][j] + (long long) f[i - 1][j] * (j - k)) % M);
                }
            }
        }
        return f[goal][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0920_H
