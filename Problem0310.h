//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0310_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0310_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵
    // 假设我们从任意节点x开始深度优先搜索，希望得到d1、d2、next1、next2、up信息
    // 设v是搜索路径上的某个节点，u是v的前驱节点：d1[v]是以v为根的子树的高度最大值，d2[v]是以v为根的子树的高度次大值
    // up[v]是节点v向上的最大距离，next1[v]是v达到最大距离的路径上的后继，next2[v]是v达到次大距离的路径上的后继
public:
    vector<int> findMinHeightTrees(int n, const vector<vector<int>> &edges) {
        vector<int> graph[n];
        for (const auto &e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        int d1[n];
        int d2[n];
        int next1[n];
        int next2[n];
        int up[n];
        memset(d1, 0, sizeof d1);
        memset(d2, 0, sizeof d2);
        memset(up, 0, sizeof up);
        memset(next1, -1, sizeof next1);
        memset(next2, -1, sizeof next2);
        dfs1(0, -1, graph, d1, next1, d2, next2);
        dfs2(0, -1, graph, up, d1, next1, d2, next2);
        auto minh = n + 1;
        for (int v = 0; v < n; ++v) {
            minh = min(minh, max(up[v], d1[v]));
        }
        vector<int> ans;
        for (int v = 0; v < n; ++v) {
            if (minh == max(d1[v], up[v])) {
                ans.emplace_back(v);
            }
        }
        return ans;
    }

private:
    void dfs1(int u,
              int father,
              vector<int> graph[],
              int d1[],
              int next1[],
              int d2[],
              int next2[]) {
        // 求解以root为根时，各个子树高度的最大值d1和次大值d2，并分别记录后继next1和next2
        for (const auto &v: graph[u]) {
            if (v == father) {
                continue;
            }
            dfs1(v, u, graph, d1, next1, d2, next2);
            auto d = d1[v] + 1;
            if (d >= d1[u]) {
                d2[u] = d1[u];
                next2[u] = next1[u];
                d1[u] = d;
                next1[u] = v;
            } else if (d > d2[u]) {
                d2[u] = d;
                next2[u] = v;
            }
        }
    }

    void dfs2(int u,
              int father,
              vector<int> graph[],
              int up[],
              int d1[],
              int next1[],
              int d2[],
              int next2[]) {
        // 求解以root为根时，向上延伸的最大长度
        for (const auto &v: graph[u]) {
            if (v == father) {
                continue;
            }
            if (next1[u] == v) {  // root的向下最大路径经过x，选择次大路径
                up[v] = max(up[u], d2[u]) + 1;
            } else {
                up[v] = max(up[u], d1[u]) + 1;
            }
            dfs2(v, u, graph, up, d1, next1, d2, next2);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0310_H
