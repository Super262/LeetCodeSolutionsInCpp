//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0111_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0111_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0111 {
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        if (root->left && root->right) {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
        if (root->left) {
            return minDepth(root->left) + 1;
        }
        return minDepth(root->right) + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0111_H
