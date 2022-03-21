//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0235_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0235_H

#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val > q->val) {  // 特殊的输入情况
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
