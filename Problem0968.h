//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0968_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0968_H

#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
LeetCode 968 - Binary Tree Cameras

树形 DP，给每个节点定义 3 个状态：

    f[u][0]:
        u 没有 camera，并且 u 当前没有被覆盖。

    f[u][1]:
        u 没有 camera，但 u 已经被某个孩子的 camera 覆盖。

    f[u][2]:
        u 自己安装了 camera。

--------------------------------------------------

状态转移：

1. u 未被覆盖：f[u][0]

    u 自己没有 camera，
    并且不能被孩子覆盖。

    因此每个孩子必须已经被覆盖，
    但不能依赖 u 的 camera。

    child 可取：
        state 1：已覆盖，无 camera
        state 2：自己有 camera

    所以：

    f[u][0] =
        min(f[L][1], f[L][2]) +
        min(f[R][1], f[R][2])

--------------------------------------------------

2. u 已被覆盖但没有 camera：f[u][1]

    u 必须由至少一个孩子的 camera 覆盖。

    因此至少一个 child 必须是 state 2。

    两种情况：

        左孩子有 camera：
            f[L][2] + min(f[R][1], f[R][2])

        右孩子有 camera：
            f[R][2] + min(f[L][1], f[L][2])

    取最小值。

--------------------------------------------------

3. u 自己有 camera：f[u][2]

    u 的 camera 可以覆盖孩子，
    所以孩子可以处于任意状态：

        state 0 / 1 / 2

    因此：

    f[u][2] =
        1 +
        min(f[L][0], f[L][1], f[L][2]) +
        min(f[R][0], f[R][1], f[R][2])

--------------------------------------------------

空节点状态：

    {0, 0, INF}

含义：
    空节点不产生费用，
    但不能安装 camera。

--------------------------------------------------

最终答案：

    根节点不能处于 state 0，
    因为根没有父节点可以继续覆盖它。

    answer =
        min(f[root][1], f[root][2])

--------------------------------------------------

复杂度：

    每个节点只访问一次。

    时间 O(n)
    空间 O(h)   // DFS 递归栈，h 为树高

核心：
    用 3 个状态分别表示“未覆盖 / 已覆盖 / 有 camera”，
    根据父子覆盖关系做树形 DP。
*/

class Solution {
public:
    int minCameraCover(struct TreeNode* root)
    {
        if (!root)
            return 0;
        
        int answer[3];
        dfsDP(root, answer);
        
        return min(answer[1], answer[2]);
    }

private:
    void dfsDP(struct TreeNode* root, int *result)
    {
        int right_cost[3];
        int left_cost[3];
        int left_min_cost = 0;
        int right_min_cost = 0;

        result[0] = 0;
        result[1] = 0x3f3f3f3f;
        result[2] = 1;

        if (root->left)
        {
            dfsDP(root->left, left_cost);
            left_min_cost = min(left_cost[1],
                                left_cost[2]);

            result[2] += min(left_cost[0],
                             min(left_cost[1],
                                 left_cost[2]));
        }
        
        if (root->right)
        {
            dfsDP(root->right, right_cost);
            right_min_cost = min(right_cost[1],
                                 right_cost[2]);

            result[2] += min(right_cost[0],
                             min(right_cost[1],
                                 right_cost[2]));
        }

        result[0] += left_min_cost + right_min_cost;

        if (root->left)
            result[1] = min(result[1],
                            left_cost[2] +
                            right_min_cost);

        if (root->right)
            result[1] = min(result[1],
                            right_cost[2] +
                            left_min_cost);
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0968_H
