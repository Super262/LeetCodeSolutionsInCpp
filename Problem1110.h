//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1110_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1110_H

#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 基于后序遍历：返回值为可以加入结果集的头节点
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        unordered_set<int> targets(to_delete.begin(), to_delete.end());
        vector<TreeNode *> result;
        root = post_order(root, targets, result);
        if (root) {
            result.emplace_back(root);
        }
        return result;
    }

private:
    TreeNode *post_order(TreeNode *root, const unordered_set<int> &targets, vector<TreeNode *> &result) {
        if (!root) {
            return root;
        }
        root->left = post_order(root->left, targets, result);
        root->right = post_order(root->right, targets, result);
        if (targets.count(root->val) == 0) {
            return root;
        }
        if (root->left) {
            result.emplace_back(root->left);
        }
        if (root->right) {
            result.emplace_back(root->right);
        }
        return nullptr;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1110_H
