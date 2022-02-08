//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0623_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0623_H

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
    // 经典算法，直接背诵：BFS找到depth-1行，修改队列中的点
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
