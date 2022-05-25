//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0375_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0375_H

#include <cstring>
#include <iostream>

using namespace std;

class Solution {
    // f[i][j]：目标值 i <= x <= j 时，所有猜法中最坏情况的最小值
    // 区间DP，从小到大枚举区间长度；在选k的前提条件下，最坏情况所用钱数为max(f[i,k-1],f[k+1,j])+k
public:
    int getMoneyAmount(const int &n) {
        int f[n + 2][n + 2];
        memset(f, 0, sizeof f);  // 注意，初始值为0：区间[i:j]中有1个或更少的数时（i >= j），代价为0
        for (int len = 2; len <= n; ++len) {
            for (int st = 1; st + len - 1 <= n; ++st) {
                auto ed = st + len - 1;
                f[st][ed] = INT_MAX;
                for (int k = st; k <= ed; ++k) {
                    f[st][ed] = min(f[st][ed], max(f[st][k - 1], f[k + 1][ed]) + k);
                }
            }
        }
        return f[1][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0375_H
