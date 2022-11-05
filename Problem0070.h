//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0070_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0070_H

class Problem0070 {
    // f[i]：到达位置i的方案数
public:
    int climbStairs(int n) {  // 滑动窗口优化
        int f[3];
        f[1] = f[0] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i % 3] = f[(i - 1) % 3] + f[(i - 2) % 3];
        }
        return f[n % 3];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0070_H
