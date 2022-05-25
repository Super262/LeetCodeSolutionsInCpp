//
// Created by Fengwei Zhang on 5/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0366_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0366_H

#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
    // DFS，类似后序遍历，自底向上累加高度、保存结果
public:
    vector<vector<int>> findLeaves(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> ans;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode *root, vector<vector<int>> &ans) {
        int d = 0;
        if (root->left) {
            d = max(dfs(root->left, ans) + 1, d);
        }
        if (root->right) {
            d = max(dfs(root->right, ans) + 1, d);
        }
        if ((int) ans.size() <= d) {
            ans.resize(d + 1);
        }
        ans[d].emplace_back(root->val);
        return d;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0366_H
