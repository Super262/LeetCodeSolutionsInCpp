//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0629_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0629_H

#include <cstring>

using namespace std;

class Solution {
    // f[i][j]：由1～i构成的包含j个逆序对的所有排列的个数；初始时，f[1][0]=1，其余为0
    // 从小到大枚举数字i；转移时，对于f[i][j]，由于i是最大的，所以将数字i插入之前i-1个数的排列中，可能产生0～i-1个逆序对（考虑数字i的插入位置）
    // 因此，若j<i，那么f[i][j]=f[i-1][0]+f[i-1][1]+...+f[i-1][j]；若j>=i，f[i][j]=f[i-1][j-(i-1)]+...+f[i-1][j]
    // 如果我们按照以上方程计算，复杂度是O(n^2*k)；经观察，我们发现上述求和公式具有前缀和的性质；我们可以维护1个变量s，s=sum({f[i-1][j]})
    // 经典DP，必须掌握，注意优化：https://www.acwing.com/solution/content/483/
public:
    int kInversePairs(const int n, const int k) {
        const int M = 1e9 + 7;
        int f[n + 1][k + 1];
        memset(f, 0, sizeof f);
        f[1][0] = 1;  // 初始化：i=1时，仅当j=0时存在有效排列
        for (int i = 2; i <= n; ++i) {
            long long s = 0;
            for (int j = 0; j <= k; ++j) {
                s += f[i - 1][j];
                if (j >= i) {
                    s -= f[i - 1][j - i];
                }
                f[i][j] = (int) (s % M);
            }
        }
        return (f[n][k] + M) % M;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0629_H
