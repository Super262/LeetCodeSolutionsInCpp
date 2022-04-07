//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0865_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0865_H

#include <algorithm>

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
public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        return dfs(root, 1).first;
    }

private:
    pair<TreeNode *, int> dfs(TreeNode *root, int depth) {  // 返回包含最深点的树根和最大深度
        if (!root) {
            return {nullptr, depth - 1};
        }
        auto lp = dfs(root->left, depth + 1);
        auto rp = dfs(root->right, depth + 1);
        if (lp.first && rp.first) {
            if (lp.second > rp.second) {
                return lp;
            }
            if (rp.second > lp.second) {
                return rp;
            }
            return {root, lp.second};
        }
        if (lp.first) {
            return lp;
        }
        if (rp.first) {
            return rp;
        }
        return {root, depth};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0865_H
