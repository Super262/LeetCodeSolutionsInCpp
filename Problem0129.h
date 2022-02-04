//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0129_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0129_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // DFS解法，必须掌握
public:
    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode *root, const int prev) {
        if (!root->left && !root->right) {
            return prev + root->val;
        }
        int s = 0;
        if (root->left) {
            s += dfs(root->left, 10 * (prev + root->val));
        }
        if (root->right) {
            s += dfs(root->right, 10 * (prev + root->val));
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0129_H
