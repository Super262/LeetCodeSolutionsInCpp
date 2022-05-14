//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0173_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0173_H

#include <stack>
#include "treenode.h"

using namespace std;

class BSTIterator {
    // 使用栈存储后继节点，用指针保存未来入栈的起点
public:
    BSTIterator(TreeNode *r) {
        root = r;
    }

    int next() {
        while (root) {
            stk.emplace(root);
            root = root->left;
        }

        root = stk.top();
        stk.pop();
        auto res = root->val;
        root = root->right;
        return res;
    }

    bool hasNext() {
        return !stk.empty() || root;
    }

private:
    TreeNode *root;
    stack<TreeNode *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0173_H
