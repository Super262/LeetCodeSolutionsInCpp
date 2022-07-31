//
// Created by Fengwei Zhang on 7/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0776_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0776_H

#include <vector>
#include "treenode.h"

using namespace std;

class Problem0776 {
    // 递归处理，类似先序遍历；每棵子树都会被拆分成2部分
public:
    vector<TreeNode *> splitBST(TreeNode *root, int target) {
        if (!root) {
            return {nullptr, nullptr};
        }
        if (root->val <= target) {
            auto ans = splitBST(root->right, target);
            root->right = ans[0];
            ans[0] = root;
            return ans;
        }
        auto ans = splitBST(root->left, target);
        root->left = ans[1];
        ans[1] = root;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0776_H
