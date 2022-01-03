//
// Created by Fengwei Zhang on 1/3/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1192_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1192_H

#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, const vector<vector<int>> &connections) {
        vector<vector<int>> graph(n);
        int disc[n + 1];
        int low[n];
        memset(disc, 0, sizeof disc);
        memset(low, 0, sizeof low);
        int time_stamp = 0;
        for (const auto &conn: connections) {
            graph[conn[0]].emplace_back(conn[1]);
            graph[conn[1]].emplace_back(conn[0]);
        }
        vector<vector<int>> result;
        Tarjan(0, -1, disc, low, graph, time_stamp, result);
        return result;
    }

private:
    void Tarjan(const int u,
                const int p,
                int disc[],
                int low[],
                const vector<vector<int>> &graph,
                int &time_stamp,
                vector<vector<int>> &result) {
        ++time_stamp;
        disc[u] = time_stamp;
        low[u] = time_stamp;
        for (const auto &v: graph[u]) {
            if (!disc[v]) {
                Tarjan(v, u, disc, low, graph, time_stamp, result);
                low[u] = min(low[u], low[v]);
                if (disc[u] < low[v]) {
                    result.push_back({u, v});
                }
            } else if (v != p) {  // 本题无重边，因此p指示父节点编号即可
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1192_H
