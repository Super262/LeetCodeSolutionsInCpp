//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0100_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0100_H

#include "treenode.h"

class Problem0100 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0100_H
