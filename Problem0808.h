//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0808_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0808_H

#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    // 动态规划，f[a][b]：A剩余a、B剩余b时，达到目标状态（汤A先分配完的概率 + 汤A和汤B同时分配完的概率/2）的概率值
    // https://www.acwing.com/solution/content/49691/
    // 由于所有操作的数值均是25的倍数，所以我们规约n为ceil(n/25)
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
