//
// Created by Fengwei Zhang on 7/3/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0651_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0651_H

#include <algorithm>

using namespace std;

class Solution {
    // 贪心，最后一步操作一定是Ctrl-V或输出"A"；动态规划，f[i]是操作n次后的最多字符数
    // 我们枚举上次执行全选操作（Ctrl-A）的位置j，易知2<=j<=i-2，那么f[i]=max({f[j-1]*(i-j)})
public:
    int maxA(int n) {
        int f[n + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            for (int j = 2; j <= i - 2; ++j) {
                f[i] = max(f[i], f[j - 1] * (i - j));
            }
        }
        return f[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0651_H
