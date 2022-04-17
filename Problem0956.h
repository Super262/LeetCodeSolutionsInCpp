//
// Created by Fengwei Zhang on 4/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0956_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0956_H

#include <vector>
#include <numeric>
#include <cstring>

using namespace std;

class Solution {
    // 转化为背包问题，f[i][j]：从前i个钢筋中选择，j是左牌高度和右牌高度的差值，当前左牌高度的最大值
    // 设所有钢筋的长度之和为m，易知-m <= j <= m；因此，我们枚举j' = j + m，0 <= j' <= 2 * m
public:
    int tallestBillboard(const vector<int> &rods) {
        const auto n = (int) rods.size();
        const auto m = accumulate(rods.begin(), rods.end(), 0);
        int f[n + 1][2 * m + 1];
        memset(f, -0x3f, sizeof f);
        f[0][m] = 0;  // 初始化：f[0][0 + m] = 0
        for (int i = 1; i <= n; ++i) {
            for (int j = -m; j <= m; ++j) {
                auto x = rods[i - 1];
                f[i][j + m] = f[i - 1][j + m];  // 不选当前的钢筋
                if (j - x >= -m) {  // 尝试将当前钢筋加入左牌
                    f[i][j + m] = max(f[i][j + m], f[i - 1][j - x + m] + x);
                }
                if (j + x <= m) {  // 尝试将当前钢筋加入右牌
                    f[i][j + m] = max(f[i][j + m], f[i - 1][j + x + m]);
                }
            }
        }
        return f[n][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0956_H
