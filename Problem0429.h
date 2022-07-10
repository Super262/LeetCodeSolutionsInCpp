//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0429_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0429_H

#include <vector>
#include <queue>
#include "node_nary.h"

using namespace std;

class Solution {
    // 层序遍历，类似二叉树
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> ans;
        queue<Node *> q;
        q.emplace(root);
        while (!q.empty()) {
            vector<int> cur;
            cur.reserve(q.size());
            for (auto k = (int) q.size(); k > 0; --k) {
                auto node = q.front();
                q.pop();
                cur.emplace_back(node->val);
                for (const auto &kid: node->children) {
                    q.emplace(kid);
                }
            }
            ans.emplace_back(cur);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0429_H
