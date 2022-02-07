//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0207_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0207_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 经典算法：检测拓扑序是否存在
public:
    bool canFinish(const int n, const vector<vector<int>> &edges) {
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
        int cnt = 0;
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            ++cnt;
            for (const auto &v: graph[root]) {
                --in_degree[v];
                if (!in_degree[v]) {
                    q.emplace(v);
                }
            }
        }
        return cnt == n;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0207_H
