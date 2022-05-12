//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0112_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0112_H

#include <queue>
#include "treenode.h"

using namespace std;

class Solution {
    // BFS，必须掌握
public:
    bool hasPathSum(TreeNode *root, const int target) {
        if (!root) {
            return false;
        }
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, root->val);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            auto node = p.first;
            auto s = p.second;
            if (!node->left && !node->right) {
                if (s == target) {
                    return true;
                }
            }
            if (node->left) {
                q.emplace(node->left, s + node->left->val);
            }
            if (node->right) {
                q.emplace(node->right, s + node->right->val);
            }
        }
        return false;
    }
};

/*class Solution {
    // DFS，必须掌握
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        sum -= root->val;
        if (!root->left && !root->right) {
            return sum == 0;
        }
        return (root->left && hasPathSum(root->left, sum)) || (root->right && hasPathSum(root->right, sum));
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0112_H
