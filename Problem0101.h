//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0101_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0101_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0101 {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right || left->val != right->val) {
            return false;
        }
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0101_H
