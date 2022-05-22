//
// Created by Fengwei Zhang on 5/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0314_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0314_H

#include "treenode.h"
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
    // 层序遍历，保持每列的层序关系；根结点的列号为0， 向左减1，向右加1
    // 利用Map维持列的有序性
public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        if (!root) {
            return {};
        }
        map<int, vector<int>> data;
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto cnt = (int) q.size();
            for (int i = 0; i < cnt; ++i) {
                auto t = q.front();
                q.pop();
                auto node = t.first;
                auto col = t.second;
                data[col].emplace_back(node->val);
                if (node->left) {
                    q.emplace(node->left, col - 1);
                }
                if (node->right) {
                    q.emplace(node->right, col + 1);
                }
            }
        }
        vector<vector<int>> ans;
        ans.reserve(data.size());
        for (const auto &item: data) {
            ans.emplace_back(item.second);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0314_H
