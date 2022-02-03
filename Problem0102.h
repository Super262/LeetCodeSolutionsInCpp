//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0102_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0102_H

#include <vector>
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
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto curSize = (int) q.size();
            vector<int> values;
            while (curSize--) {
                auto rt = q.front();
                q.pop();
                values.emplace_back(rt->val);
                if (rt->left) {
                    q.emplace(rt->left);
                }
                if (rt->right) {
                    q.emplace(rt->right);
                }
            }
            res.emplace_back(values);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0102_H
