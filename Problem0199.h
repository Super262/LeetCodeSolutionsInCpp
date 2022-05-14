//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0199_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0199_H

#include <vector>
#include <queue>
#include "treenode.h"

using namespace std;

class Solution {
    // 层序遍历，保存每层最后一个点
public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<int> ans;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto length = (int) q.size();
            while (length) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
                if (length == 1) {
                    ans.emplace_back(node->val);
                }
                --length;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0199_H
