//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0222_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0222_H

class Problem0222 {
    // 时间复杂度：O((logN)^2)
private:
    int countNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }
        auto lc = root;
        auto rc = root;
        int lh = 1;
        int rh = 1;
        while (lc->left) {
            lc = lc->left;
            ++lh;
        }
        while (rc->right) {
            rc = rc->right;
            ++rh;
        }
        if (lh == rh) {
            return (1 << lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0222_H
