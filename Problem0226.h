//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0226_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0226_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0226_H
