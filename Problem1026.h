//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1026_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1026_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Problem1026 {
    // 类似先序遍历；当前节点与所有祖先节点差值的最大值，只和所有祖先节点的最大值、最小值相关
    // 由于数据范围较小，我们直接遍历整棵树
public:
    int maxAncestorDiff(TreeNode *root) {
        if (!root) {
            return INT_MIN;
        }
        int ans = INT_MIN;
        dfs(root, root->val - 1, root->val + 1, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int pre_max, int pre_min, int &ans) {
        ans = max(ans, max(abs(root->val - pre_max), abs(root->val - pre_min)));
        if (root->left) {
            dfs(root->left, max(pre_max, root->val), min(pre_min, root->val), ans);
        }
        if (root->right) {
            dfs(root->right, max(pre_max, root->val), min(pre_min, root->val), ans);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1026_H
