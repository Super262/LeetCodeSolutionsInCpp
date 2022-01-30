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
        bool dp[s.size()][s.size()];  // s[i, j]是回文串，dp[i][j] == true（i，j从0开始）
        memset(dp, 0, sizeof dp);
        string result;
        for (int length = 1; length <= (int) s.size(); ++length) {
            for (int l = 0; l + length - 1 < (int) s.size(); ++l) {
                auto r = l + length - 1;
                if (length == 1) {
                    dp[l][r] = true;
                } else if (length == 2) {
                    dp[l][r] = s[l] == s[r];
                } else {
                    dp[l][r] = s[l] == s[r] && dp[l + 1][r - 1];
                }
                if (dp[l][r] && r - l + 1 > (int) result.size()) {
                    result = s.substr(l, r - l + 1);
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0005_H
