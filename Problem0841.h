//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0841_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0841_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(const vector<vector<int>> &graph) {
        const auto n = (int) graph.size();
        bool visited[n];
        memset(visited, 0, sizeof visited);
        bfs(0, graph, visited);
        for (int v = 0; v < n; ++v) {
            if (!visited[v]) {
                return false;
            }
        }
        return true;
    }

private:
    static void bfs(int u, const vector<vector<int>> &graph, bool visited[]) {
        queue<int> q;
        q.emplace(u);
        visited[u] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (const auto &v: graph[t]) {
                if (visited[v]) {
                    continue;
                }
                q.emplace(v);
                visited[v] = true;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0841_H
