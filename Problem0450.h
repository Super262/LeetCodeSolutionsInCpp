//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0450_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0450_H

#include "treenode.h"

class Problem0450 {
    // BST基本操作，必知必会，直接背诵
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) {
            return nullptr;
        }
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (!root->left && !root->right) {
            return nullptr;
        }
        if (root->right) {
            root->val = successor(root);
            root->right = deleteNode(root->right, root->val);
        } else {
            root->val = predecessor(root);
            root->left = deleteNode(root->left, root->val);
        }
        return root;
    }

private:
    int successor(TreeNode *root) {
        root = root->right;
        while (root->left) {
            root = root->left;
        }
        return root->val;
    }

    int predecessor(TreeNode *root) {
        root = root->left;
        while (root->right) {
            root = root->right;
        }
        return root->val;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0450_H
