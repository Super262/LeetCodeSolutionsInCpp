//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0637_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0637_H

#include <vector>
#include <queue>

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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto cnt = (int) q.size();
            double sum = 0;
            for (int i = 0; i < cnt; ++i) {
                auto t = q.front();
                q.pop();
                sum += t->val;
                if (t->left) {
                    q.emplace(t->left);
                }
                if (t->right) {
                    q.emplace(t->right);
                }
            }
            res.emplace_back(sum / cnt);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0637_H
