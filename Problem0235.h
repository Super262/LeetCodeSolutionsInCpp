//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0235_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0235_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
    // 类似前序遍历，注意细节：p->val可能大于q->val
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val > q->val) {
            swap(p, q);
        }
        if (p->val <= root->val && q->val >= root->val) {
            return root;
        }
        if (p->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return lowestCommonAncestor(root->right, p, q);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0235_H
