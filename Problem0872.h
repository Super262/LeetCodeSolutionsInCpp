//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0872_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0872_H

#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 遍历所有叶节点，直接比较
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> a;
        vector<int> b;
        getLeaves(root1, a);
        getLeaves(root2, b);
        return a == b;
    }

private:
    void getLeaves(TreeNode *root, vector<int> &ans) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            ans.emplace_back(root->val);
            return;
        }
        getLeaves(root->left, ans);
        getLeaves(root->right, ans);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0872_H
