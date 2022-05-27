//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0404_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0404_H

#include "treenode.h"

class Solution {
    // 类似先序遍历，判断当前节点的左儿子是否为叶节点
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
