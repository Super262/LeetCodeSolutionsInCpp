//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0236_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0236_H

#include "treenode.h"

class Problem0236 {
    // 简化版LCA算法，类似后序遍历
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q) {
            return nullptr;
        }
        if (p == root || q == root) {
            return root;
        }
        auto left_anc = lowestCommonAncestor(root->left, p, q);  // 向左查找包含p或q的子树
        auto right_anc = lowestCommonAncestor(root->right, p, q);  // 向右查找包含p或q的子树
        if (left_anc && right_anc) {
            return root;
        }
        if (left_anc) {
            return left_anc;
        }
        return right_anc;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0236_H
