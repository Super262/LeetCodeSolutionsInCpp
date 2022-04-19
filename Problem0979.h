//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0979_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0979_H

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

class Solution {
    // 递归处理：树u内的移动次数 = |u的节点数 - u的节点权值和| + u的左子树内的移动次数 + u的右子树内的移动次数
public:
    int distributeCoins(TreeNode *root) {
        return dfs(root).moves;
    }

private:
    struct Tuple {
        int node_cnt;
        int val_sum;
        int moves;
    };

    Tuple dfs(TreeNode *root) {
        if (!root) {
            return {0, 0, 0};
        }
        auto lt = dfs(root->left);
        auto rt = dfs(root->right);
        Tuple ans{lt.node_cnt + rt.node_cnt + 1, root->val + lt.val_sum + rt.val_sum, lt.moves + rt.moves};
        ans.moves += abs(ans.val_sum - ans.node_cnt);
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0979_H
