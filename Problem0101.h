//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0101_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0101_H

#include <queue>

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
    // 迭代法，直接背诵
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        queue<TreeNode *> q;
        q.emplace(root);
        q.emplace(root);
        while (q.size() >= 2) {
            auto *u = q.front();
            q.pop();
            auto *v = q.front();
            q.pop();
            if (!u && !v) {
                continue;
            }
            if (!u || !v) {
                return false;
            }
            if (u->val != v->val) {
                return false;
            }
            q.emplace(u->left);
            q.emplace(v->right);
            q.emplace(u->right);
            q.emplace(v->left);
        }
        return true;
    }
};

/*class Solution {
    // 递归法
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right || left->val != right->val) {
            return false;
        }
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0101_H
