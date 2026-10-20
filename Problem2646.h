//
// Created by Fengwei Zhang on 10/19/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2646_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2646_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

/*
LeetCode 2646 - Minimize the Total Price of the Trips

整体分两步：

1. 统计每个节点在所有 trip 中被经过的次数。
2. 在树上做 DP，决定哪些节点价格减半。

--------------------------------------------------
第一步：BFS 统计节点频率

因为原图是一棵树，
任意两个节点 start -> end 的路径唯一。

对于每个 trip：

    1. BFS 从 start 出发。
    2. 用 parent[] 记录搜索树中的父节点。
    3. 找到 end 后，从 end 沿 parent[] 回溯到 start。
    4. 路径上的每个节点 counter[u]++。

优化：
    parent[] 和 BFS queue 只 malloc 一次，
    每个 trip 通过 memset(parent, -1, ...) 复用，
    避免重复分配内存。

统计完成后：

    weight[u] = counter[u] * price[u]

表示节点 u 在所有 trips 中产生的总费用。

--------------------------------------------------
第二步：树形 DP

任选节点 0 作为根。

定义：

    f[u][0] =
        u 不减半时，
        以 u 为根的子树的最小总费用。

    f[u][1] =
        u 减半时，
        以 u 为根的子树的最小总费用。

初始化：

    f[u][0] = weight[u]
    f[u][1] = weight[u] / 2

转移：

    如果 u 不减半：

        child v 可以减半，也可以不减半

        f[u][0] += min(f[v][0], f[v][1])

    如果 u 减半：

        相邻节点不能同时减半，
        所以 child v 必须不减半

        f[u][1] += f[v][0]

最终答案：

    min(f[0][0], f[0][1])

--------------------------------------------------
复杂度：

设 trips 数量为 T。

每个 trip 做一次 BFS：
    O(n)

总路径统计：
    O(T * n)

树形 DP：
    O(n)

总时间复杂度：
    O(T * n)

空间复杂度：
    O(n)

核心：

    先把所有 trips 对树的影响压缩成每个节点的访问次数，
    再把问题转化为：

    “在树上选择一组互不相邻的节点进行减半，
     使总费用最小。”

这本质上是一个树上的独立集型 DP。
*/

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
