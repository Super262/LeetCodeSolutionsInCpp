//
// Created by Fengwei Zhang on 11/1/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0099_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0099_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0099 {
    // https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
    // https://www.acwing.com/solution/content/181/
private:
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
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0099_H
