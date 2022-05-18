//
// Created by Fengwei Zhang on 5/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0276_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0276_H

#include <cstring>

class Solution {
    // f[i][j]：涂色[0:i-1]柱子，第i号柱子颜色为j的方案数
    // 我们可以让第i-1号柱子为其他颜色，或者让第i-1号柱子颜色为j，但第i-2号柱子为其他颜色
    // f[i][j]=sum{f[i-1][p]|p!=j}+sum{f[i-2][p]|p!=j}；进一步优化：f[i]=f[i-1]*(k-1)+f[i-2]*(k-2)
public:
    int numWays(int n, int k) {
        if (n == 1) {
            return k;
        }
        int f[2];
        f[0] = k;
        f[1] = k * k;
        for (int i = 2; i < n; ++i) {
            f[i % 2] = f[(i - 1) % 2] * (k - 1) + f[(i - 2) % 2] * (k - 1);
        }
        return f[(n - 1) % 2];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0276_H
