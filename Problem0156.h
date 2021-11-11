//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0156_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0156_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (!root || !root->left) {
            return root;
        }
        return dfs(root->left, root, root->right);
    }

    TreeNode *dfs(TreeNode *left, TreeNode *parent, TreeNode *right) {
        TreeNode *result = nullptr;
        if (left->left) {
            result = dfs(left->left, left, left->right);
        } else {
            result = left;
        }
        left->right = parent;
        left->left = right;
        parent->left = nullptr;
        parent->right = nullptr;
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0156_H
