//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0257_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0257_H

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
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        // 时空复杂度：O(n^2)
        vector<int> path;
        vector<string> result;
        dfs(root, path, result);
        return result;
    }

private:
    void dfs(TreeNode *root, vector<int> &path, vector<string> &result) {
        if (!root) {
            return;
        }
        path.emplace_back(root->val);
        if (!root->left && !root->right) {
            string temp = to_string(path[0]);
            for (int i = 1; i < (int) path.size(); ++i) {
                temp += "->" + to_string(path[i]);
            }
            result.emplace_back(temp);
            path.pop_back();
            return;
        }
        dfs(root->left, path, result);
        dfs(root->right, path, result);
        path.pop_back();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0257_H
