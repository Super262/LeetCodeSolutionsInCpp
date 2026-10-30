//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0834_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0834_H

#include <vector>
#include <stack>
#include <cstring>

using namespace std;

/*
LeetCode 834 - Sum of Distances in Tree

换根 DP。

--------------------------------------------------
整体遍历思路：

这道题需要两遍遍历：

1. 第一遍：后序遍历

   目标：
       计算每个节点的 subtreeSize[u]，
       同时计算 answer[0]。

   subtreeSize[u] =
       以 0 为根时，u 子树中的节点数量。

   因为 subtreeSize[u] 依赖所有 child 的 subtreeSize，
   所以必须先处理 child，再处理 parent，
   即使用后序遍历。

   使用 stack<pair<int, bool>> 模拟递归后序 DFS：

       (u, false):
           第一次访问 u。
           先压入 (u, true)，
           再压入所有 children。

       (u, true):
           第二次访问 u。
           此时所有 children 都已经处理完成，
           可以计算 subtreeSize[u]。

   同时可以利用：

       answer[0] =
           sum(subtreeSize[v]), v != 0

   来得到节点 0 到所有节点的距离和。

   原因：
       对每一条 parent -> child 边，
       child 子树中的每个节点到 root 0 的路径
       都必须经过这条边一次。

       因此这条边对 answer[0] 的贡献就是：

           subtreeSize[child]

--------------------------------------------------

2. 第二遍：前序遍历 / 从 root 向 child 换根

   第一遍已经得到：

       answer[0]

   接下来利用换根公式，
   从 parent 的答案 O(1) 推出 child 的答案。

   因为 answer[v] 依赖 answer[u]，
   所以必须保证先计算 parent，再计算 child。

   因此第二遍按 root -> child 的方向遍历即可。

--------------------------------------------------
换根公式：

假设 v 是 u 的 child。

现在已知：

    answer[u] =
        u 到所有节点的距离之和。

把根从 u 移动到 v 后：

1. v 子树中的节点

   一共有：

       subtreeSize[v]

   个。

   对这些节点来说，
   新根 v 比旧根 u 更近一步。

   所以每个节点距离 -1：

       总变化 =
           -subtreeSize[v]

2. v 子树之外的节点

   一共有：

       n - subtreeSize[v]

   个。

   对这些节点来说，
   从 v 出发需要先经过 u，

   所以每个节点距离 +1：

       总变化 =
           +(n - subtreeSize[v])

因此：

    answer[v]
        = answer[u]
          - subtreeSize[v]
          + (n - subtreeSize[v])

        = answer[u]
          + n
          - 2 * subtreeSize[v]

这就是换根 DP 的核心公式。

--------------------------------------------------
潜在常数优化：用一个 int 代替 pair<int, bool>

当前第一遍使用：

    stack<pair<int, bool>>

来区分：

    (u, false)   第一次访问
    (u, true)    第二次访问

可以进一步将状态编码进一个 int，
从而避免 pair<int, bool>。

直观上可以考虑：

    u     -> 第一次访问
    -u    -> 第二次访问

但本题节点编号包含 0，而：

    -0 == 0

所以节点 0 无法区分第一次和第二次访问。

更安全的写法是使用按位取反：

    u     -> 第一次访问
    ~u    -> 第二次访问

因为对于所有 u >= 0：

    ~u < 0

并且可以通过：

    u = ~x

恢复原节点编号。

例如：

    u = 3
    ~u = -4
    ~(-4) = 3

于是可以写成：

    stack<int> stk;

    stk.push(0);

    while (!stk.empty())
    {
        int x = stk.top();
        stk.pop();

        if (x >= 0)
        {
            int u = x;

            // 第二次访问
            stk.push(~u);

            // 再压入 children
            ...
        }
        else
        {
            // 第二次访问，children 已处理完成
            int u = ~x;

            ...
        }
    }

也可以使用：

    -(u + 1)

进行编码。

这种优化不会改变时间复杂度，
只是减少 pair 的存储和访问开销，
属于常数级优化。

--------------------------------------------------
复杂度：

第一遍后序遍历：
    O(n)

第二遍换根遍历：
    O(n)

总时间复杂度：
    O(n)

空间复杂度：
    O(n)
*/

class Problem0834
{
public:
    vector<int> sumOfDistancesInTree(int n, const vector<vector<int>>& edges)
    {
        /*
         * 建立无向树。
         */
        vector<vector<int>> graph(n);
        for (const auto &e : edges)
        {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }

        /*
         * answer[u]:
         * 节点 u 到树中所有节点的距离之和。
         */
        vector<int> answer(n, 0);

        /*
         * parent[u]:
         * 以 0 为根时，u 的 parent。
         *
         * subtreeSize[u]:
         * 以 0 为根时，u 子树中的节点数量。
         */
        int *parent = (int *)malloc(n * sizeof(int));
        int *subtreeSize = (int *)malloc(n * sizeof(int));

        /*
         * stk1:
         * 用于模拟后序遍历。
         *
         * pair.second == false:
         *     第一次访问节点。
         *
         * pair.second == true:
         *     第二次访问节点，
         *     此时所有 children 已经处理完成。
         *
         * 潜在优化：
         *     可以用 stack<int>，
         *     用 u / ~u 编码第一次、第二次访问，
         *     从而省掉 pair<int, bool>。
         *
         * stk2:
         * 用于第二遍 parent -> child 的换根遍历。
         */
        stack<pair<int, bool>> stk1;
        stack<int> stk2;

        /*
         * parent == -1 表示尚未确定 parent。
         *
         * root 0 的 parent 设置成自己，
         * 防止遍历时重新走回 root。
         */
        memset(parent, -1, n * sizeof(int));
        parent[0] = 0;

        /*
         * 第一遍：
         * 后序遍历。
         *
         * 计算：
         *     subtreeSize[u]
         *     answer[0]
         */
        stk1.emplace(0, false);

        while (!stk1.empty())
        {
            auto [u, visited] = stk1.top();
            stk1.pop();

            if (visited)
            {
                /*
                 * 第二次访问 u。
                 *
                 * 此时所有 child 的 subtreeSize
                 * 都已经计算完成。
                 */
                for (auto v : graph[u])
                {
                    if (v == parent[u])
                        continue;

                    /*
                     * 汇总 child 子树大小。
                     */
                    subtreeSize[u] += subtreeSize[v];

                    /*
                     * parent -> child 这条边，
                     * 会被 child 子树中的每个节点
                     * 到 root 0 的路径经过一次。
                     *
                     * 因此这条边对 answer[0] 的贡献为：
                     *
                     *     subtreeSize[v]
                     */
                    answer[0] += subtreeSize[v];
                }
            }
            else
            {
                /*
                 * 第一次访问 u。
                 *
                 * 先把 (u, true) 压回栈，
                 * 保证 u 会在 children 之后再次被处理。
                 */
                stk1.emplace(u, true);

                /*
                 * 每个节点的子树至少包含自己。
                 */
                subtreeSize[u] = 1;

                /*
                 * 将所有 children 压入栈。
                 */
                for (auto v : graph[u])
                {
                    if (v == parent[u])
                        continue;

                    parent[v] = u;
                    stk1.emplace(v, false);
                }
            }
        }

        /*
         * 第二遍：
         * 从 root 向下做换根 DP。
         *
         * 已知 answer[u]，
         * O(1) 推出 child v 的 answer[v]。
         */
        stk2.emplace(0);

        while (!stk2.empty())
        {
            auto u = stk2.top();
            stk2.pop();

            for (auto v : graph[u])
            {
                if (v == parent[u])
                    continue;

                /*
                 * 从 u 换根到 child v：
                 *
                 * v 子树中的 subtreeSize[v] 个节点：
                 *     距离全部 -1
                 *
                 * 其余 n - subtreeSize[v] 个节点：
                 *     距离全部 +1
                 *
                 * 所以：
                 *
                 * answer[v]
                 *   = answer[u]
                 *     - subtreeSize[v]
                 *     + (n - subtreeSize[v])
                 *
                 *   = answer[u]
                 *     + n
                 *     - 2 * subtreeSize[v]
                 */
                answer[v] =
                    answer[u]
                    + n
                    - 2 * subtreeSize[v];

                stk2.emplace(v);
            }
        }

        free(parent);
        free(subtreeSize);

        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0834_H
