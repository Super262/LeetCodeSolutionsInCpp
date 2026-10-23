//
// Created by Fengwei Zhang on 10/22/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2378_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2378_H

#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

/*
LeetCode 2378 - Choose Edges to Maximize Score in a Tree

本质：
    在树上选择若干条边，使任意节点最多只属于一条被选中的边，
    并最大化所有被选边的权重和。

这是一个树上的 matching DP。

--------------------------------------------------

状态定义：

    f(u, 0):
        u 与 parent 之间的边没有被选择时，
        以 u 为根的子树能够获得的最大 score。

    f(u, 1):
        u 与 parent 之间的边已经被选择时，
        以 u 为根的子树能够获得的最大 score。

--------------------------------------------------

状态转移：

先假设 u 不选择任何 child edge。

对于每个 child v：

    base += f(v, 0)

因为不选择 u-v 时，
v 与 parent 的边没有被选择。

如果选择边 u-v：

    原本 v 子树贡献：
        f(v, 0)

    选择后贡献：
        w(u,v) + f(v, 1)

因此选择 u-v 带来的额外收益：

    gain =
        w(u,v) + f(v, 1) - f(v, 0)

由于一个节点最多只能属于一条被选中的边，
所以 u 最多只能选择一个 child edge。

因此只需要保留最大的 gain：

    bestGain =
        max(0, max(gain))

最终：

    f(u, 1) = base

        u-parent 已经被选，
        u 不能再选择任何 child edge。

    f(u, 0) = base + bestGain

        u-parent 没有被选，
        u 可以不选 child edge，
        或选择收益最大的一条。

--------------------------------------------------

非递归后序遍历：

树形 DP 必须先计算 child，再计算 parent。

使用 stack<pair<int, bool>>：

    (u, false):
        第一次访问 u。
        将 (u, true) 重新压栈，
        再把所有 child 压栈。

    (u, true):
        第二次访问 u。
        此时所有 child 已经完成 DP，
        可以计算 f(u, 0/1)。

这样显式模拟递归 DFS 的后序遍历，
避免 n 很大时递归栈溢出。

--------------------------------------------------

最终答案：

    root 没有 parent edge，

所以：

    answer = f(0, 0)

--------------------------------------------------

复杂度：

    每个节点、每条边只处理常数次。

    时间 O(n)
    空间 O(n)

核心：
    先计算“不选任何 child edge”的 base，
    再从所有 child edge 中选择最大的一次额外收益。

    因为 u 最多只能匹配一条边，
    所以不需要 knapsack，只需要维护 bestGain。
*/

class Problem2378
{
public:
    long long maxScore(vector<vector<int>>& edges)
    {
        long long answer = 0;
        const int n = (int)edges.size();
        vector<vector<pair<int, int>>> graph(n);
        long long *_f_ = (long long *)calloc(n * 2, sizeof(long long));
#define f(u, i) (_f_[(u) * 2 + (i)])

        for (int i = 1; i < n; ++i)
        {
            auto &e = edges[i]; 
            graph[e[0]].emplace_back(i, e[1]);
        }

        stack<pair<int, bool>> stk;
        stk.emplace(0, false);

        while (!stk.empty())
        {
            auto p = stk.top();
            stk.pop();

            if (!p.second)
            {
                stk.emplace(p.first, true);

                for (auto &e : graph[p.first])
                    stk.emplace(e.first, false);

                continue;
            }

            long long base = 0;
            long long bestGain = 0;
            int u = p.first;

            for (auto &e : graph[u])
            {
                int v = e.first;
                int w = e.second;

                base += f(v, 0);
                bestGain = max(bestGain, f(v, 1) + w - f(v, 0));
            }

            f(u, 1) = base;
            f(u, 0) = base + bestGain;
        }

        answer = f(0, 0);

#undef f
        free(_f_);
        return answer;
    }
};
#endif // LEETCODESOLUTIONSINCPP_PROBLEM2378_H
