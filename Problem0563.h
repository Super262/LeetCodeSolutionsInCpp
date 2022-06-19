//
// Created by Fengwei Zhang on 1/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0563_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0563_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
    // 类似后序遍历，获得左子树、右子树的元素和ls、rs，然后累加abs(ls-rs)到答案
public:
    int findTilt(TreeNode *root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode *root, int &ans) {
        if (!root) {
            return 0;
        }
        auto ls = dfs(root->left, ans);
        auto rs = dfs(root->right, ans);
        ans += abs(ls - rs);
        return ls + rs + root->val;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0563_H
