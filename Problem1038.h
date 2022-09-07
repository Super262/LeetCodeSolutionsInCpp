//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1038_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1038_H

#include "treenode.h"

class Problem1038 {
    // 类似中序遍历，先遍历右子树
public:
    TreeNode *bstToGst(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        int suffix = 0;
        return greaterSum(root, suffix);
    }

private:
    TreeNode *greaterSum(TreeNode *root, int &suffix) {
        if (root->right) {
            greaterSum(root->right, suffix);
        }
        suffix += root->val;
        root->val = suffix;
        if (root->left) {
            greaterSum(root->left, suffix);
        }
        return root;
    }
};

// 非递归写法（借助栈；也可用morris遍历）
/*class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        auto cur = root;
        int sum = 0;
        stack<TreeNode*> stk;
        while(!stk.empty() || cur) {
            while (cur) {
                stk.emplace(cur);
                cur = cur->right;
            }
            if (!stk.empty()) {
                cur = stk.top();
                stk.pop();
                cur->val += sum;
                sum = cur->val;
                cur = cur->left;
            }
        }
        return root;
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1038_H
