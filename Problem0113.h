//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0113_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0113_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0113 {
public:
    vector <vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector <vector<int>> result;
        vector<int> temp;
        if (root) {
            dfs(root, targetSum, temp, result);
        }
        return result;
    }

    void dfs(TreeNode *root, const int &target, vector<int> &temp, vector <vector<int>> &result) {
        temp.emplace_back(root->val);
        if (!root->left && !root->right) {
            if (target == root->val) {
                result.emplace_back(vector<int>(temp));
            }
        } else {
            if (root->left) {
                dfs(root->left, target - root->val, temp, result);
            }
            if (root->right) {
                dfs(root->right, target - root->val, temp, result);
            }
        }
        temp.pop_back();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0113_H
