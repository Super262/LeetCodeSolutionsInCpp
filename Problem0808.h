//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0808_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0808_H

#include <algorithm>
#include <cstring>

using namespace std;

class Problem0808 {
    // 动态规划，f[a][b]：A剩余a、B剩余b时，达到目标状态（汤A先分配完的概率 + 汤A和汤B同时分配完的概率/2）的概率值
    // 由于所有操作的数值均是25的倍数，所以我们规约n为ceil(n/25)；这4种操作对应的A、B体积增量分别是(-4,0)，(-3,-1)，(-2,-2)，(-1,-3)
    // 时间复杂度为O(n^2)；由于n可能高达10^9，我们必须继续减少计算量；经观察，可以发现：4种操作中，A肯定减少；因此，n无限大时，A一定先被分完，
    // f为1；由于精度要求为10^(-5)，经测试，n超过500*25时，可直接返回1
public:
    double soupServings(int n) {
        n = (n + 24) / 25;
        if (n >= 500) {
            return 1.0;
        }
        double f[n + 1][n + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 0.5;  // a = 0, b = 0
        for (int a = 0; a <= n; ++a) {
            for (int b = 0; b <= n; ++b) {
                if (a && !b) {  // a > 0, b = 0
                    f[a][b] = 0;
                    continue;
                }
                if (!a && b) {  // a = 0, b > 0
                    f[a][b] = 1;
                    continue;
                }
                // a > 0, b > 0
                f[a][b] = (f[max(a - 4, 0)][b] +
                           f[max(a - 3, 0)][max(b - 1, 0)] +
                           f[max(a - 2, 0)][max(b - 2, 0)] +
                           f[max(a - 1, 0)][max(b - 3, 0)]) / 4.0;
            }
        }
        return f[n][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0808_H
