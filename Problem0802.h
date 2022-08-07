//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0802_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0802_H

#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Problem0802 {
    // 拓扑排序；将原图的所有边反向，然后拓扑序输出节点，相当于从原图的终端点找到所有安全点
public:
    vector<int> eventualSafeNodes(const vector<vector<int>> &t) {
        const auto n = (int) t.size();
        vector<vector<int>> graph(n);
        int degree[n];  // 统计入度
        memset(degree, 0, sizeof degree);
        for (int u = 0; u < n; ++u) {  // 翻转原图
            for (const auto &v: t[u]) {
                graph[v].emplace_back(u);
                ++degree[u];
            }
        }
        queue<int> q;
        for (int v = 0; v < n; ++v) {
            if (!degree[v]) {
                q.emplace(v);
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (const auto &v: graph[u]) {
                --degree[v];
                if (!degree[v]) {
                    q.emplace(v);
                }
            }
        }
        vector<int> ans;
        for (int v = 0; v < n; ++v) {
            if (degree[v]) {
                continue;
            }
            ans.emplace_back(v);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0802_H
