//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0623_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0623_H

#include <queue>
#include "treenode.h"

using namespace std;

class Solution {
    // 题目要求将新节点添加到第depth层（depth>=1）；BFS层序遍历，搜索到第depth-1层，即保存depth-1层节点到队列
    // 遍历队列中depth-1层的节点，添加新节点到下层
public:
    TreeNode *addOneRow(TreeNode *root, const int val, const int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        queue<TreeNode *> q;
        q.emplace(root);
        for (int i = 0; i < depth - 2; ++i) {
            for (int k = (int) q.size(); k > 0; --k) {
                auto t = q.front();
                q.pop();
                if (t->left) {
                    q.emplace(t->left);
                }
                if (t->right) {
                    q.emplace(t->right);
                }
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto left = new TreeNode(val, t->left, nullptr);
            auto right = new TreeNode(val, nullptr, t->right);
            t->left = left;
            t->right = right;
        }
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0623_H
