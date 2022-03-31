//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0814_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0814_H

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
