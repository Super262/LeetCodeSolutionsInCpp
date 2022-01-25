//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0515_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0515_H

#include <vector>
#include <queue>
#include <unordered_map>

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
    vector<int> largestValues(TreeNode *root) {
        if (!root) {
            return {};
        }
        unordered_map<int, int> level_maximal;
        queue<TreeNode *> q;
        q.emplace(root);
        int level = 0;
        while (!q.empty()) {
            auto width = (int) q.size();
            int maximal = INT_MIN;
            while (width--) {
                auto t = q.front();
                q.pop();
                maximal = max(maximal, t->val);
                if (t->left) {
                    q.emplace(t->left);
                }
                if (t->right) {
                    q.emplace(t->right);
                }
            }
            level_maximal[level] = maximal;
            ++level;
        }
        vector<int> res(level);
        for (const auto &x: level_maximal) {
            res[x.first] = x .second;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0515_H
