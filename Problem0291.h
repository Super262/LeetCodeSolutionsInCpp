//
// Created by Fengwei Zhang on 5/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0291_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0291_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 直接DFS，枚举分界点
public:
    bool wordPatternMatch(const string &pattern, const string &s) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        return dfs(pattern, 0, s, 0, p2s, s2p);
    }

private:
    bool dfs(const string &p,
             int u1,
             const string &s,
             int u2,
             unordered_map<char, string> &p2s,
             unordered_map<string, char> &s2p) {
        if (u1 == (int) p.size()) {
            return u2 == (int) s.size();
        }
        string t;
        for (int i = u2; i < (int) s.size(); ++i) {
            t += s[i];
            if (!p2s.count(p[u1]) && !s2p.count(t)) {
                p2s[p[u1]] = t;
                s2p[t] = p[u1];
                if (dfs(p, u1 + 1, s, i + 1, p2s, s2p)) {
                    return true;
                }
                p2s.erase(p[u1]);
                s2p.erase(t);
                continue;
            }
            if (!p2s.count(p[u1]) || !s2p.count(t)) {
                continue;
            }
            if (p2s[p[u1]] != t || s2p[t] != p[u1]) {
                return false;
            }
            if (dfs(p, u1 + 1, s, i + 1, p2s, s2p)) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0291_H
