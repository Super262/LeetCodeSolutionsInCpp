//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0851_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0851_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // ans[v]：v的所有可达节点u中quiet[u]最小的节点
    // 记忆化搜索，自底向上返回结果
public:
    vector<int> loudAndRich(const vector<vector<int>> &richer, const vector<int> &quiet) {
        const auto n = (int) quiet.size();
        vector<int> graph[n];
        for (const auto &r: richer) {
            graph[r[1]].emplace_back(r[0]);
        }
        vector<int> ans(n, -1);
        for (int u = 0; u < n; ++u) {
            dfs(u, graph, quiet, ans);
        }
        return ans;
    }

private:
    void dfs(int u, const vector<int> graph[], const vector<int> &quiet, vector<int> &ans) {
        if (ans[u] != -1) {
            return;
        }
        ans[u] = u;
        for (const auto &v: graph[u]) {
            dfs(v, graph, quiet, ans);
            if (quiet[ans[u]] > quiet[ans[v]]) {
                ans[u] = ans[v];
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0851_H
