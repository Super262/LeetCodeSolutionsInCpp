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
        unordered_set<string> dict(words.begin(), words.end());
        const int n = (int) s.size();
        bool f[n + 1];  // f[i]：前i个字符是否可被分割（1 <= i <= n）
        memset(f, 0, sizeof f);
        f[0] = true;
        for (int r = 1; r <= n; ++r) {
            for (int l = 1; l <= r; ++l) {
                f[r] = f[r] || (f[l - 1] && dict.count(s.substr(l - 1, r - l + 1)));
                if (f[r]) {
                    break;
                }
            }
        }
        vector<string> temp_segs;
        vector<string> result;
        dfs(n - 1, s, dict, f, temp_segs, result);
        return result;
    }

private:
    void dfs(const int ed,
             const string &s,
             const unordered_set<string> &dict,
             bool f[],
             vector<string> &temp_segs,
             vector<string> &result) {  // 搜索s[0:ed]的所有分割方案
        if (ed < 0) {
            string path;
            reverse(temp_segs.begin(), temp_segs.end());
            for (const auto &seg: temp_segs) {
                path += seg;
                path += " ";
            }
            path.pop_back();
            result.emplace_back(path);
            reverse(temp_segs.begin(), temp_segs.end());
            return;
        }
        for (auto st = ed; st >= 0; --st) {
            auto seg = s.substr(st, ed - st + 1);
            if (!dict.count(seg) || !f[st]) {
                continue;
            }
            temp_segs.emplace_back(seg);
            dfs(st - 1, s, dict, f, temp_segs, result);
            temp_segs.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0140_H
