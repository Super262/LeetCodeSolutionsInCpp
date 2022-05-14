//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0230_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0230_H

#include "treenode.h"

class Solution {
    // 类似中序遍历，有序访问BST
public:
    int kthSmallest(TreeNode *root, int k) {
        int answer = -1;
        dfs(root, k, answer);
        return answer;
    }

private:
    bool dfs(TreeNode *root, int &k, int &answer) {  // 细节：k是引用
        if (!root) {
            return false;
        }
        if (dfs(root->left, k, answer)) {
            return true;
        }
        --k;
        if (k == 0) {
            answer = root->val;
            return true;
        }
        return dfs(root->right, k, answer);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0230_H
