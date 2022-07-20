//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0743_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0743_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0743 {
    // Dijkstra求从s到其它所有点的最短路径的长度；答案即为所有最短路中的最大值
    // 注意细节：最外层循环执行n次（n是节点个数）
public:
    int networkDelayTime(const vector<vector<int>> &times, const int n, const int s) {
        const int INF = 0x3f3f3f3f;
        int graph[n + 1][n + 1];
        memset(graph, 0x3f, sizeof graph);
        for (const auto &e: times) {
            graph[e[0]][e[1]] = min(graph[e[0]][e[1]], e[2]);
        }
        int dist[n + 1];
        bool selected[n + 1];
        memset(dist, 0x3f, sizeof dist);
        memset(selected, 0, sizeof selected);
        dist[s] = 0;
        for (int k = 1; k <= n; ++k) {
            int closest_v = -1;
            for (int v = 1; v <= n; ++v) {
                if (selected[v]) {
                    continue;
                }
                if (closest_v == -1 || dist[v] < dist[closest_v]) {
                    closest_v = v;
                }
            }
            if (dist[closest_v] == INF) {
                return -1;
            }
            selected[closest_v] = true;
            for (int v = 1; v <= n; ++v) {
                dist[v] = min(dist[v], dist[closest_v] + graph[closest_v][v]);
            }
        }
        auto res = 0;
        for (int v = 1; v <= n; ++v) {
            res = max(res, dist[v]);
        }
        return res == INF ? -1 : res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0743_H
