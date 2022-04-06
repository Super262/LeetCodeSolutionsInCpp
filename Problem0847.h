//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0847_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0847_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
    // f[s][v]：经过的所有点为s、最后位于点v的最短路径的长度
    // 存在循环依赖，不能用递推式求解动态规划，只能用图算法（多源最短路）
    // https://www.acwing.com/solution/content/615/
public:
    int shortestPathLength(const vector<vector<int>> &graph) {
        const auto n = (int) graph.size();
        int f[1 << n][n];
        memset(f, 0x3f, sizeof f);
        queue<pair<int, int>> q;
        for (int v = 0; v < n; ++v) {  // 多个源点
            auto s = 1 << v;
            f[s][v] = 0;
            q.emplace(s, v);
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto s = t.first;
            auto u = t.second;
            for (const auto &v: graph[u]) {
                auto ns = s | (1 << v);
                if (f[ns][v] <= f[s][u] + 1) {
                    continue;
                }
                f[ns][v] = f[s][u] + 1;
                q.emplace(ns, v);
            }
        }
        int ans = 0x3f3f3f3f;
        for (int v = 0, s = (1 << n) - 1; v < n; ++v) {
            ans = min(ans, f[s][v]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0847_H
