//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0691_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0691_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 我们暴力枚举所有字符串的组合情况s（二进制数表示状态），返回最小的、使s=(1<<n)-1的字符串个数
    // 记忆化搜索：f[s]表示状态s时需要的贴纸数量，g[s][ch]表示状态s结合字符ch后的后继状态
public:
    int minStickers(const vector<string> &strs, const string &target) {
        const auto n = (int) target.size();
        vector<int> f(1 << n, -1);
        vector<vector<int>> g(1 << n, vector<int>(26, -1));
        auto ans = dfs(0, strs, target, f, g);
        if (ans == INF) {
            return -1;
        }
        return ans;
    }

private:
    int dfs(int s, const vector<string> &strs, const string &target, vector<int> &f, vector<vector<int>> &g) {
        if (f[s] != -1) {
            return f[s];
        }
        const auto n = (int) target.size();
        if (s == (1 << n) - 1) {
            f[s] = 0;
            return f[s];
        }
        f[s] = INF;
        for (const auto &word: strs) {
            auto nxt = s;
            for (const auto &ch: word) {
                nxt = fill(nxt, ch, target, g);
            }
            if (s == nxt) {
                continue;
            }
            f[s] = min(f[s], dfs(nxt, strs, target, f, g) + 1);
        }
        return f[s];
    }

    int fill(int s, char ch, const string &target, vector<vector<int>> &g) {  // 返回当前状态s集合字符ch后的状态
        auto idx = ch - 'a';
        if (g[s][idx] != -1) {
            return g[s][idx];
        }
        g[s][idx] = s;
        for (int i = 0; i < (int) target.size(); ++i) {
            if (!((s >> i) & 1) && target[i] == ch) {
                g[s][idx] += 1 << i;
                return g[s][idx];
            }
        }
        return g[s][idx];
    }

    const int INF = 0x3f3f3f3f;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0691_H
