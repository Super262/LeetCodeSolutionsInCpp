//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0815_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0815_H

#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Problem0815 {
    // BFS；有向图，边(u,i)表示车站u可达编号为i的公交线路；从起点开始搜索，直到终点
public:
    int numBusesToDestination(const vector<vector<int>> &routes, int st, int ed) {
        if (st == ed) {
            return 0;
        }
        const auto n = (int) routes.size();
        unordered_map<int, vector<int>> graph;
        int dist[n];
        unordered_set<int> visited;
        queue<int> q;
        memset(dist, 0x3f, sizeof dist);
        for (int i = 0; i < n; ++i) {
            for (const auto &x: routes[i]) {
                if (x == st) {
                    q.emplace(i);
                    dist[i] = 1;
                }
                graph[x].emplace_back(i);
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (const auto &x: routes[u]) {
                if (visited.count(x)) {
                    continue;
                }
                if (x == ed) {
                    return dist[u];
                }
                for (const auto &v: graph[x]) {
                    if (dist[v] <= dist[u] + 1) {
                        continue;
                    }
                    dist[v] = dist[u] + 1;
                    q.emplace(v);
                }
                visited.emplace(x);
            }
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0815_H
