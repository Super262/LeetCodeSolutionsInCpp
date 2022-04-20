//
// Created by Fengwei Zhang on 4/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0988_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0988_H

#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 暴力法：遍历出所有的字符串，逐个比较
public:
    string smallestFromLeaf(TreeNode *root) {
        if (!root) {
            return "";
        }
        string path;
        string ans;
        dfs(root, path, ans);
        return ans;
    }

private:
    void dfs(TreeNode *u, string &path, string &ans) {
        path.push_back((char) ('a' + u->val));
        if (!u->left && !u->right) {
            reverse(path.begin(), path.end());
            if (ans.empty() || ans > path) {
                ans = path;
            }
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        if (u->left) {
            dfs(u->left, path, ans);
        }
        if (u->right) {
            dfs(u->right, path, ans);
        }
        path.pop_back();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0988_H
