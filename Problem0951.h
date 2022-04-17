//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0951_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0951_H

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
    // 递归处理：r1的左等于r2的右、r1的右等于r2的左，也可能是r1的左等于r2的左、r1的右等于r2的右
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1 || !root2) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0951_H
