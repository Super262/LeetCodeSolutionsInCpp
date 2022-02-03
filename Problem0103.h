//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0103_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0103_H

#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        int k = 1;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto curSize = (int) q.size();
            vector<int> values;
            while (curSize--) {
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
