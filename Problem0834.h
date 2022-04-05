//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0834_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0834_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 树上DP：设(u,v)是一条无向边，cnt[v]是以v为根的子树中的节点个数
    // down[v]是v到以v为根的子树中所有的点的路径和，up[v]是v到v的上部（包括u）中所有节点的路径和
    // down[u] = sum{down[v] + cnt[v]}
    // up[v] = up[u] + down[u] - (cnt[v] + down[v]) + (n - cnt[v])
public:
    vector<int> sumOfDistancesInTree(int n, const vector<vector<int>> &edges) {
        vector<int> graph[n];
        int down[n];
        int up[n];
        int cnt[n];
        for (const auto &e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        dfs_down(0, -1, graph, down, cnt);
        up[0] = 0;
        dfs_up(0, -1, n, graph, down, up, cnt);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = up[i] + down[i];
        }
        return ans;
    }

private:
    void dfs_down(int u, int p, const vector<int> graph[], int down[], int cnt[]) {
        cnt[u] = 1;
        down[u] = 0;
        for (const auto &v: graph[u]) {
            if (v == p) {
                continue;
            }
            dfs_down(v, u, graph, down, cnt);
            down[u] += down[v] + cnt[v];
            cnt[u] += cnt[v];
        }
    }

    void dfs_up(int u, int p, int n, const vector<int> graph[], int down[], int up[], int cnt[]) {
        for (const auto &v: graph[u]) {
            if (v == p) {
                continue;
            }
            up[v] = up[u] + down[u] - (cnt[v] + down[v]) + (n - cnt[v]);
            dfs_up(v, u, n, graph, down, up, cnt);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0834_H
