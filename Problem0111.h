//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0111_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0111_H

#include <algorithm>
#include <queue>
#include "treenode.h"

using namespace std;

class Solution {
    // 非递归解法：从根开始BFS，发现叶节点时停止搜索
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 1);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto d = t.second;
            auto node = t.first;
            if (!node->left && !node->right) {
                return d;
            }
            if (node->left) {
                q.emplace(node->left, d + 1);
            }
            if (node->right) {
                q.emplace(node->right, d + 1);
            }
        }
        return INT_MAX;
    }
};

/*class Solution {
    // 经典算法，直接背诵
    // 递归解法
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        if (root->left && root->right) {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
        if (root->left) {
            return minDepth(root->left) + 1;
        }
        return minDepth(root->right) + 1;
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0111_H
