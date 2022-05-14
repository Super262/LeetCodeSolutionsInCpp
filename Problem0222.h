//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0222_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0222_H

#include "treenode.h"

class Solution {
    // 由于输入是完全二叉树，我们可以根据树高来计算节点数
    // 时间复杂度：O((logN)^2)
public:
    int countNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }
        auto lc = root;
        auto rc = root;
        int lh = 1;
        int rh = 1;
        while (lc->left) {  // 统计最左侧树高
            lc = lc->left;
            ++lh;
        }
        while (rc->right) {  // 统计最右侧树高
            rc = rc->right;
            ++rh;
        }
        if (lh == rh) {  // 满二叉树，并且只有最底层为叶子节点
            return (1 << lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0222_H
