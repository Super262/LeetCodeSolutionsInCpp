//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0102_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0102_H

#include <vector>
#include <queue>
#include "treenode.h"

using namespace std;

class Problem0102 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
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
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0102_H
