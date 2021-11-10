//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0139_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0139_H

#include <string>
#include <unordered_set>
#include <vector>
#include <cstring>

using namespace std;

class Problem0139 {
public:
    bool wordBreak(const string &s, const vector<string> &wordDict) {
        unordered_set<string> dict; // 优化查找速度：Trie替代哈希表（O(n) -> O (1)）
        const int n = (int) s.size();
        bool dp[n + 1];  // dp[i]：前i个字符是否可被分割（1 <= i<= n）
        for (const auto &w: wordDict) {
            dict.insert(w);
        }
        memset(dp, 0, sizeof dp);
        dp[0] = true;
        for (int r = 1; r <= n; ++r) {
            for (int l = 1; l <= r; ++l) {
                dp[r] = dp[r] || (dp[l - 1] && dict.count(s.substr(l - 1, r - l + 1)));
                if (dp[r]) {
                    break;
                }
            }
        }
        return dp[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0139_H
