//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0113_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0113_H

#include <vector>
#include <queue>
#include <unordered_map>

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
    vector<vector<int>> pathSum(TreeNode *root, const int target) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<pair<TreeNode *, int>> q;
        unordered_map<TreeNode *, TreeNode *> parent;
        q.emplace(root, root->val);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto node = t.first;
            auto s = t.second;
            if (!node->left && !node->right) {
                if (s == target) {
                    res.emplace_back(getPath(node, parent));
                }
            }
            if (node->left) {
                parent[node->left] = node;
                q.emplace(node->left, s + node->left->val);
            }
            if (node->right) {
                parent[node->right] = node;
                q.emplace(node->right, s + node->right->val);
            }
        }
        return res;
    }

private:
    vector<int> getPath(TreeNode *root, const unordered_map<TreeNode *, TreeNode *> &parent) {
        vector<int> res;
        res.emplace_back(root->val);
        while (parent.count(root)) {
            root = parent.find(root)->second;
            res.emplace_back(root->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/*class Solution {
    // DFS解法，必须掌握
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        if (root) {
            dfs(root, targetSum, temp, result);
        }
        return result;
    }

private:
    void dfs(TreeNode *root, const int target, vector<int> &temp, vector<vector<int>> &result) {
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
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0113_H
