//
// Created by Fengwei Zhang on 2/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0700_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0700_H

#include "treenode.h"

class Solution {
    // 根据BST的性质，迭代搜索
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root && val != root->val) {
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0700_H
