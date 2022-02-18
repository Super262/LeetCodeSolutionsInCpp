//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0669_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0669_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 经典算法，必须掌握：简化的BST删除操作，若root被删除，则左、右孩子至多被保留一个
public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (!root) {
            return nullptr;
        }
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0669_H
