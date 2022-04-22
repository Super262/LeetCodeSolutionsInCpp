//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1022_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1022_H

/**
 * Definition for a binary tree node.
  */
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
    int sumRootToLeaf(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int prev, int &ans) {
        auto cur = prev + root->val;
        if (!root->left && !root->right) {
            ans += cur;
            return;
        }
        if (root->left) {
            dfs(root->left, cur * 2, ans);
        }
        if (root->right) {
            dfs(root->right, cur * 2, ans);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1022_H
