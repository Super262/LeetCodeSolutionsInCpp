//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0156_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0156_H

#include "treenode.h"

class Solution {
    // 自下而上翻转，类似后序遍历
    // 注意细节，切忌混淆指针
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (!root || !root->left) {
            return root;
        }
        return dfs(root->left, root, root->right);
    }

private:
    TreeNode *dfs(TreeNode *left, TreeNode *parent, TreeNode *right) {
        TreeNode *root = nullptr;
        if (left->left) {
            root = dfs(left->left, left, left->right);  // 处理子节点
        } else {
            root = left;
        }
        left->right = parent;  // 处理当前层
        left->left = right;
        parent->left = nullptr;
        parent->right = nullptr;
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0156_H
