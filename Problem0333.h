//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0333_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0333_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
    // 类似后序遍历
public:
    int largestBSTSubtree(TreeNode *root) {
        auto res = dfs(root);
        return res.size;
    }

private:
    struct Result {
        TreeNode *node; // 最大BST子树的根
        int upper; // 当前子树最大值
        int lower; // 当前子树最小值
        // 以上3项用于判断当前树是否为BST
        int size;  // 最大BST子树的节点数

        Result() {
            node = nullptr;
            upper = INT_MIN;
            lower = INT_MAX;
            size = 0;
        }
    };

    Result dfs(TreeNode *root) {
        if (!root) {
            return {};
        }
        Result left_res;
        Result right_res;
        if (root->left) {
            left_res = dfs(root->left);
        }
        if (root->right) {
            right_res = dfs(root->right);
        }
        auto left_is_valid = !left_res.node || (left_res.node == root->left && left_res.upper < root->val);
        auto right_is_valid = !right_res.node || (right_res.node == root->right && right_res.lower > root->val);
        if (left_is_valid && right_is_valid) {  // 左、右子树可以和root构成BST
            Result result;
            result.node = root;
            result.upper = right_res.node ? right_res.upper : root->val;
            result.lower = left_res.node ? left_res.lower : root->val;
            result.size = 1 + (right_res.node ? right_res.size : 0) + (left_res.node ? left_res.size : 0);
            return result;
        }
        if (left_res.node && right_res.node) {  // 左、右都有结果，返回大者
            return left_res.size > right_res.size ? left_res : right_res;
        }
        if (left_res.node) {
            return left_res;
        }
        return right_res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0333_H
