//
// Created by Fengwei Zhang on 10/19/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2646_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2646_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem2646
{
public:
    /* 类似AcWing 285 */
    int minimumTotalPrice(int n,
                          const vector<vector<int>>& edges,
                          const vector<int>& price,
                          const vector<vector<int>>& trips)
    {
        vector<vector<int>> graph(n);
        for (const vector<int>& e : edges)
        {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }

        /*
         * counter[u]:
         * 所有 trips 中节点 u 被经过的次数。
         */
        int *counter = (int *)calloc(n, sizeof(int));

        /*
         * parent / queue 只分配一次，
         * 后续所有 BFS 复用。
         */
        int *parent = (int *)malloc(sizeof(int) * n);
        int *queue = (int *)malloc(sizeof(int) * n);

        for (const vector<int>& t : trips)
        {
            bfsCount(t[0], t[1],
                     n, graph,
                     parent, queue, counter);
        }

        /*
         * 将访问次数转换成该节点产生的总费用。
         */
        for (int u = 0; u < n; ++u)
            counter[u] *= price[u];

        /*
         * f[u][0]:
         *     u 不减半时的子树最小费用。
         *
         * f[u][1]:
         *     u 减半时的子树最小费用。
         *
         * 使用一维连续数组压常数。
         */
        int *f = (int *)calloc((size_t)n * 2, sizeof(int));

        dfsDP(0, -1, graph, counter, f);

        int answer = min(f[0], f[1]);

        free(f);
        free(queue);
        free(parent);
        free(counter);
        return answer;
    }

private:
    void bfsCount(int start,
                  int target,
                  int n,
                  const vector<vector<int>>& graph,
                  int *parent,
                  int *queue,
                  int *counter)
    {
        /*
         * parent[u] == -1:
         *     尚未访问。
         *
         * parent[start] = start:
         *     标记起点已访问，
         *     同时让回溯终点条件更简单。
         */
        memset(parent, -1, sizeof(int) * n);

        int qHead = 0;
        int qTail = 0;

        parent[start] = start;
        queue[qTail++] = start;

        while (qHead < qTail)
        {
            int u = queue[qHead++];

            if (u == target)
                break;

            for (int v : graph[u])
            {
                if (parent[v] != -1)
                    continue;

                parent[v] = u;
                queue[qTail++] = v;
            }
        }

        /*
         * 树中 start -> target 路径唯一。
         * 沿 parent 回溯统计路径上的节点。
         */
        int u = target;

        while (u != start)
        {
            ++counter[u];
            u = parent[u];
        }

        ++counter[start];
    }

    void dfsDP(int u,
               int p,
               const vector<vector<int>>& graph,
               const int *weight,
               int *f)
    {
#define dp(u, h) (f[(u) * 2 + (h)])

        /*
         * u 不减半。
         */
        dp(u, 0) = weight[u];

        /*
         * u 减半。
         */
        dp(u, 1) = weight[u] / 2;

        for (int v : graph[u])
        {
            if (v == p)
                continue;

            dfsDP(v,
                  u,
                  graph,
                  weight,
                  f);

            /*
             * u 不减半：
             * child 可以减半，也可以不减半。
             */
            dp(u, 0) += min(dp(v, 0), dp(v, 1));

            /*
             * u 减半：
             * 相邻 child 不能减半。
             */
            dp(u, 1) += dp(v, 0);
        }

#undef dp
    }
};
#endif // LEETCODESOLUTIONSINCPP_PROBLEM2646_H
