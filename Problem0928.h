//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0928_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0928_H

#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 首先忽略所有染病的点，将未染病的、相连通的点组合成连通块
    // 统计与每个连通块相关联的、染病的点，若某个连通块只与一个染病的点x相关联，将这个连通块的体积计入x的影响因子
    // 找到影响因子最大的、编号x最小的染病的点
public:
    int minMalwareSpread(const vector<vector<int>> &graph, const vector<int> &initial) {
        const auto n = (int) graph.size();
        int parent[n];
        int com_size[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            com_size[i] = 1;
        }
        unordered_set<int> bad_nodes(initial.begin(), initial.end());
        for (int i = 0; i < n; ++i) {  // 合并所有相关联的健康节点
            if (bad_nodes.count(i)) {
                continue;
            }
            auto pi = findRoot(i, parent);
            for (int j = i + 1; j < n; ++j) {
                if (!graph[i][j] || bad_nodes.count(j)) {
                    continue;
                }
                auto pj = findRoot(j, parent);
                if (pi == pj) {
                    continue;
                }
                parent[pj] = pi;
                com_size[pi] += com_size[pj];
            }
        }
        unordered_set<int> bad_connection[n];  // 统计和某个连通块相连的染病节点
        for (const auto &x: initial) {
            for (int i = 0; i < n; ++i) {
                if (!graph[x][i] || bad_nodes.count(i)) {
                    continue;
                }
                bad_connection[findRoot(i, parent)].insert(x);
            }
        }
        int bad_factor[n];  // 统计每个染病的点的影响因子
        memset(bad_factor, 0, sizeof bad_factor);
        for (int i = 0; i < n; ++i) {
            if (bad_connection[i].size() != 1) {
                continue;
            }
            bad_factor[*bad_connection[i].begin()] += com_size[i];
        }
        auto ans = initial[0];
        for (const auto &x: initial) {
            if (bad_factor[x] > bad_factor[ans] || (bad_factor[x] == bad_factor[ans] && x < ans)) {
                ans = x;
            }
        }
        return ans;
    }

private:
    int findRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0928_H
