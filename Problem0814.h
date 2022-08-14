//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0814_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0814_H

#include "treenode.h"

class Problem0814 {
    // 后序遍历；先处理左、右子树；若左、右子树均被删去，且根结点为1，返回空值
public:
    TreeNode *pruneTree(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        auto lt = pruneTree(root->left);
        auto rt = pruneTree(root->right);
        if (!lt) {
            root->left = nullptr;
        }
        if (!rt) {
            root->right = nullptr;
        }
        if (!lt && !rt && root->val != 1) {
            return nullptr;
        }
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0814_H
