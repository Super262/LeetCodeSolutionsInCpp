//
// Created by Fengwei Zhang on 5/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0285_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0285_H

#include "treenode.h"

class Solution {
    // 首先，我们要找到节点p：若p比根小，向左搜索；若p比根大，向右搜索
    // 找到了p：若p有右孩子，p的后继应是右子树最左下的节点；否则，p的后继应是查找路径上最后大于p的节点
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *prev = nullptr;
        while (root != p) {
            if (p->val < root->val) {
                prev = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if (root->right) {
            root = root->right;
            while (root->left) {
                root = root->left;
            }
            return root;
        }
        return prev;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0285_H
