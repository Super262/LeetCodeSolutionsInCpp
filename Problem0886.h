//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0886_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0886_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, const vector<vector<int>> &dislikes) {
        vector<vector<int>> graph(n + 1);
        for (const auto &e: dislikes) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        int color[n + 1];
        memset(color, 0, sizeof color);
        for (int v = 1; v <= n; ++v) {
            if (color[v]) {
                continue;
            }
            if (!dfs(v, 1, color, graph)) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(int u, int c, int color[], const vector<vector<int>> &graph) {
        color[u] = c;
        for (const auto &v: graph[u]) {
            if (color[v] == color[u]) {
                return false;
            }
            if (!color[v] && !dfs(v, 3 - c, color, graph)) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0886_H
