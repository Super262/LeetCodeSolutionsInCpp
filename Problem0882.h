//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0882_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0882_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
    // 最短路：将边上点的个数看作边长，求最短路；根据边(u,v)的dist[u]、dist[v]来确定边上有几个点满足题意
public:
    int reachableNodes(const vector<vector<int>> &edges, int max_moves, int n) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto &e: edges) {
            graph[e[0]].emplace_back(e[1], e[2] + 1);
            graph[e[1]].emplace_back(e[0], e[2] + 1);
        }
        int dist[n];
        memset(dist, 0x3f, sizeof dist);
        dijkstra(0, n, graph, dist);
        int ans = 0;
        for (int v = 0; v < n; ++v) {
            if (dist[v] > max_moves) {
                continue;
            }
            ++ans;
        }
        for (const auto &e: edges) {
            auto a = max(0, max_moves - dist[e[0]]);
            auto b = max(0, max_moves - dist[e[1]]);
            ans += min(a + b, e[2]);
        }
        return ans;
    }

private:
    void dijkstra(int st, int n, const vector<vector<pair<int, int>>> &graph, int dist[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        bool selected[n];
        memset(selected, 0, sizeof selected);
        dist[st] = 0;
        heap.emplace(dist[st], st);
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            auto rv = t.second;
            if (selected[rv]) {
                continue;
            }
            selected[rv] = true;
            auto rd = t.first;
            for (const auto &nt: graph[rv]) {
                auto nv = nt.first;
                auto nd = nt.second;
                if (dist[nv] <= rd + nd) {
                    continue;
                }
                dist[nv] = rd + nd;
                heap.emplace(dist[nv], nv);
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0882_H
