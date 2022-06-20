//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0589_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0589_H

#include <vector>
#include "nary_node.h"

using namespace std;

class Solution {
public:
    vector<int> preorder(Node *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(Node *root, vector<int> &ans) {
        if (!root) {
            return;
        }
        ans.emplace_back(root->val);
        for (const auto &ch: root->children) {
            dfs(ch, ans);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0589_H
