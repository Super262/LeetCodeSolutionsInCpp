//
// Created by Fengwei Zhang on 9/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0005_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0005_H

#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 区间DP，dp[i][j]：s[i:j]是否为回文字符串
public:
    string longestPalindrome(const string &s) {
        const auto n = (int) s.size();
        bool f[n][n];  // s[i, j]是回文串，f[i][j] == true（i，j从0开始）
        memset(f, 0, sizeof f);
        int ans_idx = -1;
        int ans_len = 0;
        for (int length = 1; length <= n; ++length) {
            for (int l = 0; l + length - 1 < n; ++l) {
                auto r = l + length - 1;
                if (length == 1) {
                    f[l][r] = true;
                } else if (s[l] == s[r]) {
                    f[l][r] = length == 2 || f[l + 1][r - 1];
                }
                if (f[l][r] && r - l + 1 > ans_len) {
                    ans_len = r - l + 1;
                    ans_idx = l;
                }
            }
        }
        return s.substr(ans_idx, ans_len);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0005_H
