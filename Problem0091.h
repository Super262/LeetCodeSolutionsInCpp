//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0091_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0091_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int numDecodings(const string &s) {
        int dp[s.size() + 1];
        dp[0] = 1;
        for (int len = 1; len <= (int) s.size(); ++len) {
            dp[len] = 0;
            if (s[len - 1] >= '1' && s[len - 1] <= '9') {
                dp[len] += dp[len - 1];
            }
            if (len == 1) {
                continue;
            }
            int num = (int) (s[len - 2] - '0') * 10 + (int) (s[len - 1] - '0');
            if (num < 10 || num > 26) {
                continue;
            }
            dp[len] += dp[len - 2];
        }
        return dp[s.size()];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0091_H
