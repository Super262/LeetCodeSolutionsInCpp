//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0112_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0112_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0112 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        sum -= root->val;
        if (!root->left && !root->right) {
            return sum == 0;
        }
        return (root->left && hasPathSum(root->left, sum)) || (root->right && hasPathSum(root->right, sum));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0112_H
