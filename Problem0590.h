//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0590_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0590_H

#include <vector>
#include <stack>
#include "nary_node.h"

using namespace std;

class Solution {
public:
    vector<int> postorder(Node *root) {
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
            for (const auto &item: node->children) {
                if (item) {
                    stk.emplace(item);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0590_H
