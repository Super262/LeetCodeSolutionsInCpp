//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0107_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0107_H

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0107_H

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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto cur_size = (int) q.size();
            vector<int> values;
            while (cur_size--) {
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
        reverse(res.begin(), res.end());
        return res;
    }
};