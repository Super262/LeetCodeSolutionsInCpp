//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0513_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0513_H

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
    int findBottomLeftValue(TreeNode *root) {
        int ans = -1;
        int max_d = 0;
        dfs(root, 1, max_d, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int cur_d, int &max_d, int &ans) {
        if (!root) {
            return;
        }
        if (cur_d > max_d) {
            max_d = cur_d;
            ans = root->val;
        }
        dfs(root->left, cur_d + 1, max_d, ans);
        dfs(root->right, cur_d + 1, max_d, ans);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0513_H
