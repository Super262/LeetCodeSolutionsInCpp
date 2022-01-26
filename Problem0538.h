//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0538_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0538_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 按右、中、左顺序遍历
public:
    TreeNode *convertBST(TreeNode *root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }

private:
    void dfs(TreeNode *root, int &sum) {
        if (!root) {
            return;
        }
        dfs(root->right, sum);
        auto x = root->val;
        root->val += sum;
        sum += x;
        dfs(root->left, sum);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0538_H
