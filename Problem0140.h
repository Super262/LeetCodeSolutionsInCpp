//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0140_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0140_H

#include <string>
#include <unordered_set>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(const string &s, const vector<string> &words) {
        // 优化查找速度：Trie替代哈希表（O(n) -> O (1)）
        unordered_set<string> dict(words.begin(), words.end());
        const int n = (int) s.size();
        bool dp[n + 1];  // dp[i]：前i个字符是否可被分割（1 <= i<= n）
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
        vector<string> tempSegs;
        vector<string> result;
        dfs(n - 1, s, dict, dp, tempSegs, result);
        return result;
    }

private:
    void dfs(const int idx,
             const string &s,
             const unordered_set<string> &dict,
             bool dp[],
             vector<string> &temp_segs,
             vector<string> &result) {  // 搜索s[0:idx]的所有分割方案
        if (idx < 0) {
            string path;
            for (auto seg: temp_segs) {
                seg += " " + path;
                path = seg;
            }
            path.pop_back();
            result.emplace_back(path);
            return;
        }
        for (int ed = idx; ed >= 0; --ed) {
            string current = s.substr(ed, idx - ed + 1);
            if (!dict.count(current) || !dp[ed]) {
                continue;
            }
            temp_segs.emplace_back(current);
            dfs(ed - 1, s, dict, dp, temp_segs, result);
            temp_segs.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0140_H
