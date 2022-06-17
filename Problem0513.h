//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0513_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0513_H

#include "treenode.h"

class Solution {
    // 根据题意，我们采取先序遍历，找到第1个（最左侧）达到最大深度的节点
public:
    int findBottomLeftValue(TreeNode *root) {
        int ans = -1;
        int max_d = 0;
        dfs(root, 1, max_d, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int cur_d, int &max_d, int &ans) {
        if (!root) {
            return;
        }
        if (cur_d > max_d) {
            max_d = cur_d;
            ans = root->val;
        }
        dfs(root->left, cur_d + 1, max_d, ans);
        dfs(root->right, cur_d + 1, max_d, ans);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0513_H
