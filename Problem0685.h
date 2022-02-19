//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0685_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0685_H

#include <vector>
#include <stack>
#include <cstring>

using namespace std;

class Solution {
    // 经典算法，必须掌握：有向图找环
    // https://www.acwing.com/solution/content/20909/
public:
    vector<int> findRedundantDirectedConnection(const vector<vector<int>> &edges) {
        bool st1[edges.size()];  // 边i是否在环中
        bool st2[edges.size()];  // 边i是否为某个入度为2的点的前驱边
        memset(st1, 0, sizeof st1);
        memset(st2, 0, sizeof st2);
        const auto n = (int) edges.size();
        work1(edges, n, st1);
        work2(edges, n, st2);
        for (int i = (int) edges.size() - 1; i >= 0; --i) {
            if (st1[i] && st2[i]) {
                return edges[i];
            }
        }
        for (int i = (int) edges.size() - 1; i >= 0; --i) {
            if (st1[i] || st2[i]) {
                return edges[i];
            }
        }
        return {};
    }

private:
    void work1(const vector<vector<int>> &edges, int n, bool st1[]) {
        vector<vector<int>> graph(n + 1, vector<int>());
        for (const auto &e: edges) {
            graph[e[0]].emplace_back(e[1]);
        }
        bool visited[n + 1];
        bool in_stk[n + 1];  // 点v是否在栈中
        bool in_cycle[n + 1];  // 点v是否在环中
        stack<int> stk;
        memset(visited, 0, sizeof visited);
        memset(in_stk, 0, sizeof in_stk);
        memset(in_cycle, 0, sizeof in_cycle);
        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && dfs(v, graph, edges, stk, visited, in_stk, in_cycle)) {
                break;
            }
        }
        for (int i = 0; i < (int) edges.size(); ++i) {
            auto a = edges[i][0];
            auto b = edges[i][1];
            if (in_cycle[a] && in_cycle[b]) {
                st1[i] = true;
            }
        }
    }

    bool dfs(const int v,
             const vector<vector<int>> &graph,
             const vector<vector<int>> &edges,
             stack<int> &stk,
             bool visited[],
             bool in_stk[],
             bool in_cycle[]) {
        visited[v] = true;
        stk.emplace(v);
        in_stk[v] = true;
        for (const auto &x: graph[v]) {
            if (!visited[x]) {
                if (dfs(x, graph, edges, stk, visited, in_stk, in_cycle)) {
                    return true;
                }
            } else if (in_stk[x]) {
                while (!stk.empty() && stk.top() != x) {
                    in_cycle[stk.top()] = true;
                    stk.pop();
                }
                in_cycle[x] = true;
                return true;
            }
        }
        stk.pop();
        in_stk[v] = false;
        return false;
    }

    void work2(const vector<vector<int>> &edges, int n, bool st2[]) {
        int parent[n + 1];  // 点v的前驱边的编号
        memset(parent, -1, sizeof parent);
        for (int i = 0; i < (int) edges.size(); ++i) {
            auto b = edges[i][1];
            if (parent[b] == -1) {
                parent[b] = i;
            } else {
                st2[parent[b]] = true;
                st2[i] = true;
                return;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0685_H
