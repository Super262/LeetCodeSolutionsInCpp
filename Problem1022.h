//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1022_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1022_H


#include "treenode.h"

class Problem1022 {
    // 类似先序遍历
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
