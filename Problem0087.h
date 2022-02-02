//
// Created by Fengwei Zhang on 10/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0087_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0087_H

#include <string>

using namespace std;

class Solution {
    // 经典算法，直接背诵：https://www.acwing.com/solution/content/170/
public:
    bool isScramble(const string &s1, const string &s2) {
        if (s1 == s2) {
            return true;
        }
        auto temp1 = s1;
        auto temp2 = s2;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if (temp1 != temp2) {
            return false;
        }
        const int n = (int) s1.size();
        bool dp[n][n][n + 1];
        memset(dp, 0, sizeof dp);
        for (int k = 1; k <= n; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                for (int j = 0; j + k - 1 < n; ++j) {
                    if (k == 1) {
                        dp[i][j][k] = (s1[i] == s2[j]);
                    } else {
                        for (int l = 1; l < k; ++l) {
                            if (dp[i][j][l] && dp[i + l][j + l][k - l]) {
                                dp[i][j][k] = true;
                                break;
                            }
                            if (dp[i][j + k - l][l] && dp[i + l][j][k - l]) {
                                dp[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0087_H
