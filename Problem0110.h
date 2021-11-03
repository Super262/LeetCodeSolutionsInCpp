//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0110_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0110_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0110 {
public:
    bool isBalanced(TreeNode *root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode *root, bool &ans) {
        if (!root) {
            return 0;
        }
        auto lh = dfs(root->left, ans);
        auto rh = dfs(root->right, ans);
        if (abs(rh - lh) > 1) {
            ans = false;
        }
        return max(lh, rh) + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0110_H
