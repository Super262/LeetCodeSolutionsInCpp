//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0472_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0472_H

#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>

using namespace std;

class Solution {
    // 动态规划，dp[i] = k：字符串的前i个字符最多由k个单词构成
    // 字符串哈希，避免超时
public:
    vector<string> findAllConcatenatedWordsInADict(const vector<string> &words) {
        unordered_set<unsigned long long> dict;
        for (const auto &w: words) {
            unsigned long long hash = 0;
            for (const auto &ch: w) {
                hash = hash * P + ch;
            }
            dict.insert(hash);
        }
        vector<string> res;
        for (const auto &w: words) {
            if (isDividable(w, dict)) {
                res.emplace_back(w);
            }
        }
        return res;
    }

private:
    const unsigned long long P = 131;

    bool isDividable(const string &s, const unordered_set<unsigned long long> &dict) {
        const auto n = (int) s.size();
        int dp[n + 1];
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            if (dp[i] < 0) {
                continue;
            }
            unsigned long long hash = 0;
            for (auto j = i + 1; j <= n; ++j) {
                hash = hash * P + s[j - 1];
                if (!dict.count(hash)) {
                    continue;
                }
                dp[j] = max(dp[i] + 1, dp[j]);
            }
            if (dp[n] > 1) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0472_H
