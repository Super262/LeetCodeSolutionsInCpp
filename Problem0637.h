//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0637_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0637_H

#include <vector>
#include <queue>
#include "treenode.h"

using namespace std;

class Solution {
    // BFS层序遍历，计算每层节点的平均值
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
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
            ans.emplace_back(sum / cnt);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0637_H
