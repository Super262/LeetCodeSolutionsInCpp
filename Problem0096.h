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

class Problem0096 {
    // 1. 数学方法，卡特兰数：C(n + 1) = 2 * (2 * n + 1) / (n + 2) * C(n + 2)。
    // 2. 动态规划：dp[i] = dp[j - 1] * dp[i - j]（长度为i的BST种类数是左右子树的种类数的乘积）
private:
    int numTrees(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int len = 1; len <= n; ++len) {
            for (int root = 1; root <= len; ++root) {
                dp[len] += dp[root - 1] * dp[len - root];
            }
        }
        return dp[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0096_H
