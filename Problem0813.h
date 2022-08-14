//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0813_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0813_H

#include <vector>

using namespace std;

class Problem0813 {
    // 动态规划，f[i][k]：将前i个数字分成k段的方案；利用前缀和来快速求解nums[l:r]段的平均值
public:
    double largestSumOfAverages(const vector<int> &nums, int k) {
        const auto n = (int) nums.size();
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        double f[n + 1][k + 1];
        memset(f, -0x3f, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int m = 1; m <= k; ++m) {
                for (int j = 0; j < i; ++j) {
                    f[i][m] = max(f[i][m], f[j][m - 1] + (double) (prefix[i] - prefix[j]) / (i - j));
                }
            }
        }
        return f[n][k];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0813_H
