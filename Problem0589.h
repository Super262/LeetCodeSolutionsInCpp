//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0589_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0589_H

#include <vector>
#include <stack>
#include "nary_node.h"

using namespace std;

class Solution {
public:
    vector<int> preorder(Node *root) {
        if (!root) {
            return {};
        }
        vector<int> ans;
        stack<Node *> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            ans.emplace_back(node->val);
            for (auto it = node->children.rbegin(); it != node->children.rend(); it++) {
                stk.emplace(*it);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0589_H
