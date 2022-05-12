//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0114_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0114_H

#include "treenode.h"

class Solution {
    // 经典算法，必须掌握
public:
    void flatten(TreeNode *root) {
        while (root) {
            auto p = root->left;
            if (p) {
                while (p->right) {
                    p = p->right;
                }
                p->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0114_H
