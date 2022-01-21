//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0450_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0450_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // BST基本操作，必知必会；利用引用，简化操作
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        remove(root, key);
        return root;
    }

private:
    void remove(TreeNode *&root, int key) {
        if (!root) {
            return;
        }
        if (root->val == key) {
            if (!root->left && !root->right) {
                root = nullptr;
            } else if (!root->left) {
                root = root->right;
            } else if (!root->right) {
                root = root->left;
            } else {
                auto p = root->right;
                while (p->left) {
                    p = p->left;
                }
                root->val = p->val;
                remove(root->right, root->val);
            }
        } else if (key < root->val) {
            remove(root->left, key);
        } else {
            remove(root->right, key);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0450_H
