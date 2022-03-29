//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0785_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0785_H

#include <vector>

using namespace std;

class Solution {
public:
    bool isBipartite(const vector<vector<int>> &graph) {
        auto n = (int) graph.size();
        int color[n];
        memset(color, 0, sizeof color);
        for (int u = 0; u < n; ++u) {
            if (color[u]) {
                continue;
            }
            if (!dfs(u, 1, color, graph)) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(int u, int c, int color[], const vector<vector<int>> &graph) {
        color[u] = c;
        for (const auto &v: graph[u]) {
            if (color[v] == c) {
                return false;
            }
            if (!color[v] && !dfs(v, 3 - c, color, graph)) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0785_H
