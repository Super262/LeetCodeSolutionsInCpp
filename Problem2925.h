//
// Created by Fengwei Zhang on 10/23/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2925_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2925_H

#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

/*
LeetCode 2925 - Maximum Score After Applying Operations on a Tree

树形 DP + 非递归后序遍历。

定义：

    valueSum[u] =
        以 u 为根的子树中所有 values 的总和。

    f[u] =
        保证所有 u -> leaf 路径最终至少存在一个非零节点时，
        u 子树能够获得的最大 score。

--------------------------------------------------

叶子：

    f[u] = 0

因为 leaf -> leaf 路径只有 leaf 自己，
不能把 leaf 变成 0，否则该路径不再 healthy。

--------------------------------------------------

对于非叶子 u，有两种选择：

1. 对 u 执行 operation：

       获得 values[u]

   u 变成 0，所以每个 child subtree
   都必须独立保持 healthy。

       score =
           values[u] + sum(f[child])

2. 不对 u 执行 operation：

   u 保持非零，因此所有经过 u 的路径
   已经满足 healthy 条件。

   所有 descendants 都可以执行 operation：

       score =
           valueSum[u] - values[u]

所以：

    f[u] =
        max(
            values[u] + sum(f[child]),
            valueSum[u] - values[u]
        )

--------------------------------------------------

遍历：

使用 stack<pair<int, bool>> 模拟后序 DFS：

    (u, false):
        第一次访问，
        先压入 (u, true)，再压入所有 children。

    (u, true):
        children 已全部处理，
        此时计算 valueSum[u] 和 f[u]。

这样避免深树导致递归栈溢出。

--------------------------------------------------

答案：

    f[0]

复杂度：

    时间 O(n)
    空间 O(n)

核心：

    如果拿走 u，则 children 必须继续负责保证路径 healthy；
    如果保留 u，则下面所有节点都可以放心拿走。
*/

class Problem2925
{
public:
    long long maximumScoreAfterOperations(const vector<vector<int>>& edges,
                                          const vector<int>& values)
    {
        long long answer = 0;
        const int n = (int)values.size();

        vector<vector<int>> graph(n);

        /*
         * stack 中：
         *
         * (u, false) = 第一次访问 u
         * (u, true)  = 第二次访问 u，此时所有 child 已经处理完成
         *
         * 用这种方式模拟递归 DFS 的后序遍历。
         */
        stack<pair<int, bool>> stk;

        /*
         * f[u]:
         * 在以 u 为根的子树中，
         * 保证所有 u -> leaf 路径最终至少存在一个非零节点时，
         * 能够获得的最大 score。
         *
         * valueSum[u]:
         * 以 u 为根的整棵子树的 values 总和。
         */
        long long *f =
            (long long *)calloc(n, sizeof(long long));

        long long *valueSum =
            (long long *)malloc(n * sizeof(long long));

        /*
         * parent[u]:
         * 将原来的无根树转换成以 0 为根的有根树。
         */
        int *parent =
            (int *)malloc(n * sizeof(int));

        /* 建立无向树 */
        for (const auto &e : edges)
        {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }

        memset(parent, -1, n * sizeof(int));

        /*
         * 以 0 为根。
         *
         * parent[0] = 0 可以同时标记 root 已访问，
         * 防止后续从 child 再走回 root。
         */
        parent[0] = 0;
        stk.emplace(0, false);

        while (!stk.empty())
        {
            auto p = stk.top();
            int u = p.first;

            stk.pop();

            /*
             * 第一次访问 u：
             *
             * 1. 先将 (u, true) 压回 stack
             * 2. 再把所有 child 压入 stack
             *
             * 因此下一次处理 (u, true) 时，
             * 所有 child 的 f[] 和 valueSum[] 都已经计算完成。
             *
             * ---------- 关键：显式 stack 实现后序遍历 ----------
             */
            if (!p.second)
            {
                stk.emplace(u, true);

                /*
                 * 子树和至少包含 u 自己。
                 */
                valueSum[u] = values[u];

                for (int v : graph[u])
                {
                    /* 不往 parent 方向走 */
                    if (v == parent[u])
                        continue;

                    if (parent[v] == -1)
                        parent[v] = u;

                    stk.emplace(v, false);
                }

                continue;
            }

            /*
             * 第二次访问 u：
             * 所有 child 已经完成 DP。
             */
            long long scoreSum = 0;
            bool isLeaf = true;

            for (int v : graph[u])
            {
                if (v == parent[u])
                    continue;
                else if (isLeaf)
                    isLeaf = false;

                /*
                 * 汇总整个子树的 values。
                 */
                valueSum[u] += valueSum[v];

                /*
                 * 如果我们对 u 执行 operation，
                 * 那么每个 child subtree 都必须独立保持 healthy。
                 *
                 * 对应 sum(f[child])。
                 */
                scoreSum += f[v];
            }

            /*
             * 叶子节点：
             *
             * u -> leaf 的路径实际上只有 u 自己。
             *
             * 为了保证这条路径最终 sum != 0，
             * 不能对这个叶子执行 operation。
             *
             * 所以最大 score = 0。
             */
            if (isLeaf)
            {
                f[u] = 0;
            }
            else
            {
                /*
                 * 对非叶子 u 有两种选择：
                 *
                 * ------------------------------------------------
                 * 选择 1：对 u 执行 operation
                 *
                 * 得到：
                 *      values[u]
                 *
                 * 但 u 变成 0 后，不能再负责保证路径 healthy。
                 *
                 * 因此每个 child subtree 都必须自己满足条件：
                 *
                 *      score =
                 *          values[u]
                 *          + sum(f[child])
                 *
                 * 即：
                 *
                 *      scoreSum + values[u]
                 *
                 * ------------------------------------------------
                 * 选择 2：不对 u 执行 operation
                 *
                 * u 保留非零 value。
                 *
                 * 这样所有经过 u 的 u -> leaf 路径
                 * 已经至少包含一个非零节点 u，
                 * 所以所有 descendants 都可以执行 operation。
                 *
                 * 可以拿走：
                 *
                 *      subtreeSum[u] - values[u]
                 *
                 * 即：
                 *
                 *      valueSum[u] - values[u]
                 *
                 * ------------------------------------------------
                 *
                 * 两种情况取最大值。
                 */
                f[u] =
                    max(
                        scoreSum + values[u],
                        valueSum[u] - values[u]
                    );
            }
        }

        /*
         * 整棵树以 0 为根，
         * 所以最终答案就是 f[0]。
         */
        answer = f[0];

        free(parent);
        free(valueSum);
        free(f);

        return answer;
    }
};
#endif // LEETCODESOLUTIONSINCPP_PROBLEM2925_H
