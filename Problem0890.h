//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0890_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0890_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 依次验证每个字符，哈希表保存两组映射关系
public:
    vector<string> findAndReplacePattern(const vector<string> &words, const string &pattern) {
        vector<string> ans;
        for (const auto &s: words) {
            if (!checkPattern(s, pattern)) {
                continue;
            }
            ans.emplace_back(s);
        }
        return ans;
    }

private:
    static bool checkPattern(const string &s, const string &p) {
        if (s.size() != p.size()) {
            return false;
        }
        unordered_map<char, char> s2p;
        unordered_map<char, char> p2s;
        for (int i = 0; i < s.size(); ++i) {
            if (!s2p.count(s[i]) && !p2s.count(p[i])) {
                s2p[s[i]] = p[i];
                p2s[p[i]] = s[i];
                continue;
            }
            if (!s2p.count(s[i]) || !p2s.count(p[i]) || s2p[s[i]] != p[i] || p2s[p[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0890_H
