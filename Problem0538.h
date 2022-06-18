//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0538_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0538_H

#include "treenode.h"

class Solution {
    // 根据题意，若当前BST的根结点是u，我们应先遍历u的右子树，获得右子树的和，再更新u->val，再遍历左子树
    // 因此，我们按右、中、左顺序遍历BST，设置全局变量sum，sum是所有比当前根结点u大的节点的和
public:
    TreeNode *convertBST(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        int sum = 0;
        dfs(root, sum);
        return root;
    }

private:
    void dfs(TreeNode *root, int &sum) {
        if (root->right) {
            dfs(root->right, sum);
        }
        auto x = root->val;
        root->val += sum;
        sum += x;
        if (root->left) {
            dfs(root->left, sum);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0538_H
