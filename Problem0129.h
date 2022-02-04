//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0129_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0129_H

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
    // BFS解法，必须掌握
public:
    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, root->val);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto node = t.first;
            auto val = t.second;
            if (!node->left && !node->right) {
                res += val;
            }
            if (node->left) {
                q.emplace(node->left, val * 10 + node->left->val);
            }
            if (node->right) {
                q.emplace(node->right, val * 10 + node->right->val);
            }
        }
        return res;
    }
};

/*class Solution {
    // DFS解法，必须掌握
public:
    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode *root, const int prev) {
        if (!root->left && !root->right) {
            return prev + root->val;
        }
        int s = 0;
        if (root->left) {
            s += dfs(root->left, 10 * (prev + root->val));
        }
        if (root->right) {
            s += dfs(root->right, 10 * (prev + root->val));
        }
        return s;
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0129_H
