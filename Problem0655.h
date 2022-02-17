//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0655_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0655_H

#include <vector>
#include <string>

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
    // 经典算法，必须掌握
    // 递归求得宽度和深度
public:
    vector<vector<string>> printTree(TreeNode *root) {
        auto rp = dfs(root);
        auto h = rp.first;
        auto w = rp.second;
        vector<vector<string>> ans(h, vector<string>(w, ""));
        printLines(root, 0, 0, w - 1, ans);
        return ans;
    }

private:
    pair<int, int> dfs(TreeNode *root) {
        if (!root) {
            return {0, 0};
        }
        auto lp = dfs(root->left);
        auto rp = dfs(root->right);
        return {max(lp.first, rp.first) + 1, max(lp.second, rp.second) * 2 + 1};
    }

    void printLines(TreeNode *root, const int h, const int l, const int r, vector<vector<string>> &ans) {
        if (!root) {
            return;
        }
        auto mid = l + (r - l) / 2;
        ans[h][mid] = to_string(root->val);
        printLines(root->left, h + 1, l, mid - 1, ans);
        printLines(root->right, h + 1, mid + 1, r, ans);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0655_H
