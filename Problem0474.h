//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0474_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0474_H

#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(const vector<string> &strs, int m, int n) {
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof dp);
        for (const auto &s: strs) {
            int a = 0, b = 0;
            for (const auto &ch: s) {
                if (ch == '0') {
                    ++a;
                } else {
                    ++b;
                }
            }
            for (int i = m; i >= a; --i) {
                for (int j = n; j >= b; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - a][j - b] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0474_H
