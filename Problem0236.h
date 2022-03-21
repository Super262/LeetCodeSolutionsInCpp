//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0236_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0236_H

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    // 简化版LCA算法
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q) {
            return NULL;
        }
        if (p == root || q == root) {
            return root;
        }
        auto left_res = lowestCommonAncestor(root->left, p, q);  // 向左查找包含p或q的子树
        auto right_res = lowestCommonAncestor(root->right, p, q);  // 向右查找包含p或q的子树
        if (left_res && right_res) {
            return root;
        }
        if (left_res) {
            return left_res;
        }
        return right_res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0236_H
