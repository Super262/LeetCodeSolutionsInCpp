//
// Created by Fengwei Zhang on 6/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0545_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0545_H

#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
    // 先处理根结点：若根为空，直接返回空数组；若根为叶，跳过；否则，将根结点的值加入答案
    // 再处理左边界：设当前遍历到左边界的节点u；若u为叶，停止遍历；否则，将u的值加入答案；若u->left不为空，更新u=u->left；否则，更新u=u->right
    // 再处理叶节点：设u是当前子树的根；若u是叶节点，将u的值加入答案，结束；否则，递归处理左子树、右子树
    // 最后处理右边界：与处理左边界类似，最后需要翻转
public:
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        if (!root) {
            return {};
        }
        if (isLeaf(root)) {
            return {root->val};
        }
        vector<int> ans;
        ans.emplace_back(root->val);
        auto u = root->left;
        while (u) {  // 处理左侧
            if (isLeaf(u)) {  // 遇到叶子，停止
                break;
            }
            ans.emplace_back(u->val);
            if (u->left) {
                u = u->left;
            } else {
                u = u->right;
            }
        }
        addLeaves(root, ans);  // 处理叶节点
        auto st = (int) ans.size();
        u = root->right;
        while (u) {  // 处理右边界
            if (isLeaf(u)) {  // 遇到叶子，停止
                break;
            }
            ans.emplace_back(u->val);
            if (u->right) {
                u = u->right;
            } else {
                u = u->left;
            }
        }
        reverse(ans.begin() + st, ans.end());
        return ans;
    }

private:
    bool isLeaf(TreeNode *node) {
        return !node->left && !node->right;
    }

    void addLeaves(TreeNode *root, vector<int> &ans) {
        if (isLeaf(root)) {
            ans.emplace_back(root->val);
            return;
        }
        if (root->left) {
            addLeaves(root->left, ans);
        }
        if (root->right) {
            addLeaves(root->right, ans);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0545_H
