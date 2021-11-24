//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0338_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0338_H

#include <vector>

using namespace std;

class Solution {
public:
    // 递推式解法，直接背诵！
    vector<int> countBits(const int &n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0338_H
