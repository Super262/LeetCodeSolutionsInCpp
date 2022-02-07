//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0210_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0210_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
    // 经典算法，必须掌握：拓扑排序
public:
    vector<int> findOrder(const int n, const vector<vector<int>> &edges) {
        vector<int> graph[n];
        int in_degree[n];
        memset(in_degree, 0, sizeof in_degree);
        for (const auto &e: edges) {
            graph[e[1]].emplace_back(e[0]);
            ++in_degree[e[0]];
        }
        queue<int> q;
        for (int v = 0; v < n; ++v) {
            if (in_degree[v] != 0) {
                continue;
            }
            q.emplace(v);
        }
        vector<int> result;
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            result.emplace_back(root);
            for (const auto &v: graph[root]) {
                --in_degree[v];
                if (!in_degree[v]) {
                    q.emplace(v);
                }
            }
        }
        if (result.size() < n) {
            return {};
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0210_H
