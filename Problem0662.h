//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0662_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0662_H

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
    // 经典算法，必须掌握：给节点编号，节点i的孩子为2*i和2*i+1，计算每层左、右端点编号的差
    // 细节：避免编号值溢出整数，下一层编号0开始
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (!root) {
            return 0;
        }
        unsigned long long res = 1;
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
            res = max(res, ed - st + 1);
        }
        return (int) res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0662_H
