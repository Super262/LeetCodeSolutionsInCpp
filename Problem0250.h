//
// Created by Fengwei Zhang on 5/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0250_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0250_H

#include "treenode.h"

class Solution {
    // 类似后序遍历，自下而上统计
public:
    int countUnivalSubtrees(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        countHelper(root, ans);
        return ans;
    }

private:
    bool countHelper(TreeNode *root, int &cnt) {
        bool ans = true;
        if (root->left) {
            auto t = countHelper(root->left, cnt);
            ans = ans && t && root->val == root->left->val;  // 左子树是且根值和左值相等
        }
        if (root->right) {
            auto t = countHelper(root->right, cnt);
            ans = ans && t && root->val == root->right->val;  // 右子树是且根值和右值相等
        }
        if (ans) {
            ++cnt;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0250_H
