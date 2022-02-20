//
// Created by Fengwei Zhang on 2/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0700_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0700_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0700_H
