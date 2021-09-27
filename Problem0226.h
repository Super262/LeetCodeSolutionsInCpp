//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0226_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0226_H

using namespace std;

class Problem0226 {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0226_H
