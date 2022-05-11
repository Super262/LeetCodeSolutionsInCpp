//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0096_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0096_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 1. 数学方法，卡特兰数：C(n + 1) = 2 * (2 * n + 1) / (n + 2) * C(n)。
    // 2. 动态规划：f[i] = f[j - 1] * f[i - j]（长度为i的BST种类数是左右子树的种类数的乘积）
public:
    int numTrees(int n) {
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int len = 1; len <= n; ++len) {
            for (int root = 1; root <= len; ++root) {
                f[len] += f[root - 1] * f[len - root];
            }
        }
        return f[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0096_H
