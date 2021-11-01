//
// Created by Fengwei Zhang on 10/31/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0097_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0097_H

#include <string>
#include <cstring>

using namespace std;

class Problem0097 {
public:
    bool isInterleave(const string &s1, const string &s2, const string &s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        bool dp[s1.size() + 1][s2.size() + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = true;
        for (int i = 0; i <= (int) s1.size(); ++i) {
            for (int j = 0; j <= (int) s2.size(); ++j) {
                if (i && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0097_H
