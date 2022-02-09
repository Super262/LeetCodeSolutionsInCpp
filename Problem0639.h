//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0639_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0639_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 经典算法，直接背诵：DP + 空间优化
public:
    int numDecodings(const string &s) {
        const int M = 1e9 + 7;
        const auto n = (int) s.size();
        int dp[3];
        dp[0] = 1;
        for (int l = 1; l <= n; ++l) {
            dp[l % 3] = 0;  // 使用滑动窗口优化空间时，不要忘记赋初值
            for (int i = 1; i <= 26; ++i) {
                auto a = s[l - 1];
                if (i < 10) {
                    if (a == '*' || a == '0' + i) {
                        dp[l % 3] = (int) (((long long) dp[(l - 1) % 3] + dp[l % 3]) % M);
                    }
                } else if (l >= 2) {
                    auto b = s[l - 2];
                    auto y = i / 10;
                    auto x = i % 10;
                    if ((b - '0' == y || (y && b == '*')) && (a - '0' == x || (x && a == '*'))) {
                        dp[l % 3] = (int) (((long long) dp[(l - 2) % 3] + dp[l % 3]) % M);
                    }
                }
            }
        }
        return dp[n % 3];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0639_H
