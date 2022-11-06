//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0103_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0103_H

#include <vector>
#include <queue>
#include <algorithm>
#include "treenode.h"

using namespace std;

class Problem0103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        int k = 1;
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
            if (k % 2 == 0) {
                reverse(values.begin(), values.end());
            }
            res.emplace_back(values);
            ++k;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0103_H
