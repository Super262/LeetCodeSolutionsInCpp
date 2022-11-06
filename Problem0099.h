//
// Created by Fengwei Zhang on 11/1/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0099_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0099_H

#include <algorithm>
#include <stack>
#include "treenode.h"

using namespace std;

class Problem0099 {
    // 中序遍历（非递归 + 栈）
public:
    void recoverTree(TreeNode *root) {
        stack<TreeNode *> stk;
        TreeNode *x = nullptr;
        TreeNode *y = nullptr;
        TreeNode *pred = nullptr;
        while (!stk.empty() || root) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pred && root->val < pred->val) {
                y = root;
                if (!x) {
                    x = pred;
                } else {
                    break;
                }
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
};

/*class Problem0099 {
    // 直接背诵：Morris遍历
    // https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
    // https://www.acwing.com/solution/content/181/
public:
    void recoverTree(TreeNode *root) {
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *prep = nullptr;
        while (root) {
            if (root->left) {
                auto *p = root->left;
                while (p->right && p->right != root) {
                    p = p->right;
                }
                if (p->right == root) {
                    p->right = nullptr;
                    if (prep && prep->val > root->val) {
                        if (!first) {
                            first = prep;
                        }
                        second = root;
                    }
                    prep = root;
                    root = root->right;
                } else {
                    p->right = root;
                    root = root->left;
                }
            } else {
                if (prep && prep->val > root->val) {
                    if (!first) {
                        first = prep;
                    }
                    second = root;
                }
                prep = root;
                root = root->right;
            }
        }
        swap(first->val, second->val);
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0099_H
