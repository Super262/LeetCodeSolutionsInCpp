//
// Created by Fengwei Zhang on 6/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0582_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0582_H

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
    // 首先，我们根据输入建立有向图，边为(ppid,pid)；以kill为起点，BFS搜索所有可达的点
public:
    vector<int> killProcess(const vector<int> &pid, const vector<int> &ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        const auto n = (int) pid.size();
        for (int i = 0; i < n; ++i) {
            graph[ppid[i]].emplace_back(pid[i]);
        }
        vector<int> ans;
        queue<int> q;
        q.emplace(kill);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            ans.emplace_back(u);
            for (const auto &v: graph[u]) {
                q.emplace(v);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0582_H
