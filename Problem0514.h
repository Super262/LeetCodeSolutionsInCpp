//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0514_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0514_H

#include <cstring>
#include <string>

using namespace std;

class Solution {
    // dp[i][j]：拼写出key的前i个字符、ring指示在索引为j的位置时的最少操作步数
public:
    int findRotateSteps(const string &ring, const string &key) {
        int dp[key.size() + 1][ring.size()];
        memset(dp, 0x3f, sizeof dp);
        for (int j = 0; j < ring.size(); ++j) {  // 初始化
            dp[0][j] = j;
        }
        for (int i = 1; i <= key.size(); ++i) {
            for (int j = 0; j < ring.size(); ++j) {
                if (key[i - 1] != ring[j]) {
                    continue;
                }
                for (int k = 0; k < ring.size(); ++k) {
                    auto t = abs(j - k);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(t, (int) ring.size() - t) + 1);
                }
            }
        }
        int res = 0x3f3f3f3f;
        for (int i = 0; i < ring.size(); ++i) {
            res = min(res, dp[key.size()][i]);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0514_H
