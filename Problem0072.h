//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0072_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0072_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0072 {
private:
    int minDistance(const string &word1, const string &word2) {
        if (word1.empty()) {
            return (int) word2.size();
        }
        if (word2.empty()) {
            return (int) word1.size();
        }
        const int m = (int) word1.size();
        const int n = (int) word2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0072_H
