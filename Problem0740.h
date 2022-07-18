//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0740_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0740_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0740 {
    // DP，类似"股票买卖"：f[i][0]表示遍历了前i种数字，不选择第i种时的最大收益，f[i][1]表示选择第i种时的最大收益
    // 转移时，若要选取当前数字i，f[i][1]=f[i-1][0]+counter[i]*i；若不选i，则直接选前面的最大值f[i][0]=max(f[i-1][0],f[i-1][1])
public:
    int deleteAndEarn(const vector<int> &nums) {
        int counter[100001];
        memset(counter, 0, sizeof counter);
        int m = 0;
        for (const auto &x: nums) {
            m = max(m, x);
            ++counter[x];
        }
        int f[2][2];
        f[0][0] = 0;
        f[0][1] = -0x3f3f3f3f;
        for (int i = 1; i <= m; ++i) {
            f[i % 2][0] = max(f[(i - 1) % 2][0], f[(i - 1) % 2][1]);
            f[i % 2][1] = f[(i - 1) % 2][0] + counter[i] * i;
        }
        return max(f[m % 2][0], f[m % 2][1]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0740_H
