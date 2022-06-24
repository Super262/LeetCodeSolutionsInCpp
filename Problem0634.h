
//
// Created by Fengwei Zhang on 6/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0634_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0634_H

class Solution {
    // 两种解法：动态规划和容斥原理
public:
    int findDerangement1(int n) {
        // 动态规划，f[n]=(n-1)*(f[n-1]+f[n-2])；f[n]表示由n个数组成的、满足题意的排列的方案数；假设我们现在有序列[1,2,3,...,n]
        // 我们希望将这个序列转换为满足题意的序列；假设第1步，我们将数字1放置到数字i的位置；由于2<=i<=n，放置数字i，我们有以下2个选项
        // (1)交换数字i和数字1，剩余n-2个数字的方案数是f[n-2]；(2)将1放置到位置i，数字i不放置到数字1的位置，对于数字i和其它n-2个数，方案数为f[n-1]
        int f[3];
        const int M = 1e9 + 7;
        f[0] = 1;  // n=0时，方案数为1
        f[1] = 0;
        for (int i = 2; i <= n; ++i) {
            f[i % 3] = (int) (((i - 1ll) * ((long long) f[(i - 1) % 3] + f[(i - 2) % 3])) % M);
        }
        return f[n % 3];
    }

    int findDerangement2(int n) {
        // 设Ai是数字i在位置i的排列的个数，设所有排列的集合为U；答案集合为U-(A1|A2|...|An)
        // 根据容斥原理，得到答案集合的大小为n!-C(n,1)*((n-1)!)+C(n,2)*((n-2)!)+...+((-1)^p)*C(n,p)*((n-p)!)+...
        // 进一步化简，可得到n!-(n!)/(1!)+(n!)/(2!)+...
        const int M = 1e9 + 7;
        int ans = 0;
        int mul = 1;  // mul=(n!)/(i!)
        for (int i = n; i >= 0; --i) {
            ans = (int) ((((ans + (long long) (i % 2 ? -1 : 1) * mul) % M) + M) % M);
            mul = (int) (((long long) mul * i) % M);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0634_H
