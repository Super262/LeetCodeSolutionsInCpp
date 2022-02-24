//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0740_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0740_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // DP，类似"打家劫舍"：f[i][0]表示遍历了前i种数字，不选择第i种时的最大收益，f[i][1]表示选择第i种时的最大收益
    // https://www.acwing.com/solution/content/5757/
public:
    int deleteAndEarn(const vector<int> &nums) {
        int counter[N];
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

private:
    const int N = 100001;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0740_H
