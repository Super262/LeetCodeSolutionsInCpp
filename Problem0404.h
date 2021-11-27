//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0404_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0404_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }

private:
    void dfs(TreeNode *root, int &answer) {
        if (!root) {
            return;
        }
        if (root->left && !root->left->left && !root->left->right) {
            answer += root->left->val;
        }
        dfs(root->left, answer);
        dfs(root->right, answer);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0404_H
