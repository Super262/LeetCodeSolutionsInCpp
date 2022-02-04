//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0114_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0114_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 经典算法，必须掌握
public:
    void flatten(TreeNode *root) {
        while (root) {
            auto p = root->left;
            if (p) {
                while (p->right) {
                    p = p->right;
                }
                p->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0114_H
