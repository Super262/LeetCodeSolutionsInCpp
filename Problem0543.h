//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0543_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0543_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
    // 类似后序遍历，先分别获得左、右子树的深度，再计算根的直径
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int answer = 0;
        dfs(root, answer);
        return answer;
    }

private:
    int dfs(TreeNode *root, int &answer) {
        int l = 0;
        int r = 0;
        if (root->left) {
            l = dfs(root->left, answer);
        }
        if (root->right) {
            r = dfs(root->right, answer);
        }
        answer = max(answer, l + r);
        return max(l, r) + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0543_H
