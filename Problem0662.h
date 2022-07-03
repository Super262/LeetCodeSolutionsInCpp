//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0662_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0662_H

#include <queue>
#include "treenode.h"

using namespace std;

class Solution {
    // 给节点编号，节点i的孩子为2*i和2*i+1，计算每层左、右端点编号的差
    // 细节：避免编号值溢出整数，每层从0开始对节点重新编号
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (!root) {
            return 0;
        }
        unsigned long long ans = 1;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.emplace(root, 1);
        while (!q.empty()) {
            auto st = q.front().second;
            auto level_size = (int) q.size();
            auto ed = st;
            while (level_size--) {
                auto t = q.front().first;
                ed = q.front().second;
                q.pop();
                if (t->left) {
                    q.emplace(t->left, 2 * (ed - st));
                }
                if (t->right) {
                    q.emplace(t->right, 2 * (ed - st) + 1);
                }
            }
            ans = max(ans, ed - st + 1);
        }
        return (int) ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0662_H
