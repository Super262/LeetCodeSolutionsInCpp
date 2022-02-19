//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0687_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0687_H

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
    // 经典DFS，注意细节
public:
    int longestUnivaluePath(TreeNode *root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode *root, int &ans) {
        if (!root) {
            return 0;
        }
        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);
        if (!root->left || root->left->val != root->val) {
            l = 0;
        }
        if (!root->right || root->right->val != root->val) {
            r = 0;
        }
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0687_H
