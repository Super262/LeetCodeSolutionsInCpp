//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0310_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0310_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(const int &n, const vector<vector<int>> &edges) {
        vector<vector<int>> graph(n, vector<int>());
        for (const auto &e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        vector<int> d1(n, 0);
        vector<int> d2(n, 0);
        vector<int> next1(n, 0);
        vector<int> next2(n, 0);
        vector<int> up(n, 0);
        dfs1(0, -1, graph, d1, next1, d2, next2);
        dfs2(0, -1, graph, up, d1, next1, d2, next2);
        int min_h = n + 1;
        for (int i = 0; i < n; ++i) {
            min_h = min(min_h, max(d1[i], up[i]));
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (min_h == max(d1[i], up[i])) {
                result.emplace_back(i);
            }
        }
        return result;
    }

private:
    void dfs1(const int root,
              const int father,
              const vector<vector<int>> &graph,
              vector<int> &d1,
              vector<int> &next1,
              vector<int> &d2,
              vector<int> &next2) {
        // 求解以root为根时，各个子树高度的最大值d1和次大值d2，并分别记录后继next1和next2
        for (const auto &x: graph[root]) {
            if (x == father) {
                continue;
            }
            dfs1(x, root, graph, d1, next1, d2, next2);
            auto d = d1[x] + 1;
            if (d >= d1[root]) {
                d2[root] = d1[root];
                d1[root] = d;
                next2[root] = next1[root];
                next1[root] = x;
            } else if (d > d2[root]) {
                d2[root] = d;
                next2[root] = x;
            }
        }
    }

    void dfs2(const int root,
              const int father,
              const vector<vector<int>> &graph,
              vector<int> &up,
              vector<int> &d1,
              vector<int> &next1,
              vector<int> &d2,
              vector<int> &next2) {
        // 求解以root为根时，向上延伸的最大长度
        for (const auto &x: graph[root]) {
            if (x == father) {
                continue;
            }
            if (x == next1[root]) { // root的向下最大路径经过x
                up[x] = max(up[root], d2[root]) + 1; // 选择其它路径
            } else {
                up[x] = max(up[root], d1[root]) + 1;
            }
            dfs2(x, root, graph, up, d1, next1, d2, next2);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0310_H
