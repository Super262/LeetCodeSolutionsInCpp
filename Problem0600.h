//
// Created by Fengwei Zhang on 2/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0600_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0600_H

#include <algorithm>

using namespace std;

class Solution {
    // 经典算法，必须掌握：数位DP
    // https://www.acwing.com/solution/content/467/
public:
    int findIntegers(int n) {
        int dp[31];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < 31; ++i) {  // 预处理
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        bool last_one = false;
        int ans = 0;
        for (int i = 29; i >= 0; --i) {
            if ((n >> i) & 1) {
                ans += dp[i + 1];
                if (last_one) {
                    return ans;
                }
                last_one = true;
            } else {
                last_one = false;
            }
        }
        return ans + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0600_H
