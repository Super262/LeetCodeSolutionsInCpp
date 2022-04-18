//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0965_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0965_H

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
    // 直接递归判断：左、右节点是否都和根节点相等，左、右子树是否满足要求
public:
    bool isUnivalTree(TreeNode *root) {
        if (!root) {
            return true;
        }
        bool lu = !root->left || root->left->val == root->val;
        bool ru = !root->right || root->right->val == root->val;
        return lu && ru && isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0965_H
