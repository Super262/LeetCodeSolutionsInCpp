//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0115_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0115_H

#include <string>
#include <cstring>

using namespace std;

class Problem0115 {
public:
    int numDistinct(const string &s, const string &t) {
        // 最终答案不超过INT_MAX，但中间结果可能超过INT_MAX
        const int n = (int) s.size();
        const int m = (int) t.size();
        // dp[i][j]表示s[1,i]的子序列生成t[1,j]的方式数
        unsigned long long dp[2][m + 1]; // 滚动数组优化
        memset(dp, 0, sizeof dp);
        for (int i = 0; i <= n; ++i) {
            dp[i % 2][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if (s[i - 1] == t[j - 1]) {
                    dp[i % 2][j] += dp[(i - 1) % 2][j - 1];
                }
            }
        }
        return (int) dp[n % 2][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0115_H
