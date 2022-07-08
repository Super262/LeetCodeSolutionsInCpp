//
// Created by Fengwei Zhang on 2/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0701_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0701_H

#include "treenode.h"

class Solution {
    // 根据BST的性质，迭代搜索合适的插入位置
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        auto node = root;
        while (node) {
            if (val > node->val) {
                if (node->right) {
                    node = node->right;
                } else {
                    node->right = new TreeNode(val);
                    return root;
                }
            } else {
                if (node->left) {
                    node = node->left;
                } else {
                    node->left = new TreeNode(val);
                    return root;
                }
            }
        }
        return new TreeNode(val);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0701_H
