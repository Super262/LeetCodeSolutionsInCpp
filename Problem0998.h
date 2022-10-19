//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0998_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0998_H

#include "treenode.h"

class Problem0998 {
    // 若val小于根，在右子树插入新节点；若val大于根，val成为新的根，原树为新树的左子树
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val <= val) {
            auto u = new TreeNode(val);
            u->left = root;
            return u;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0998_H
