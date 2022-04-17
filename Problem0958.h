//
// Created by Fengwei Zhang on 4/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0958_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0958_H

#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 什么时候是不完全：其实就是出现null结点之后后面又出现了结点，如果是完全则最后一个null结点之后就结束遍历了
public:
    bool isCompleteTree(TreeNode *root) {
        queue<TreeNode *> q;
        bool prev_null = false;
        q.emplace(root);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (!u) {
                prev_null = true;
                continue;
            }
            if (prev_null) {
                return false;
            }
            q.emplace(u->left);
            q.emplace(u->right);
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0958_H
