//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0207_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0207_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(const int &n, const vector<vector<int>> &edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> inDegree(n, 0);
        for (const auto &e: edges) {
            graph[e[1]].emplace_back(e[0]);
            ++inDegree[e[0]];
        }
        queue<int> q;
        for (int v = 0; v < n; ++v) {
            if (inDegree[v] != 0) {
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
                --inDegree[v];
                if (!inDegree[v]) {
                    q.emplace(v);
                }
            }
        }
        return cnt == n;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0207_H
