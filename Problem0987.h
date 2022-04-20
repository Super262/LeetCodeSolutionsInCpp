//
// Created by Fengwei Zhang on 4/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0987_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0987_H

#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 先序遍历，获得所有节点的坐标(x,y)，用哈希表保存当前列（y）的所有节点
    // 依照y从小到大的顺序遍历哈希表，排序列节点，输出答案
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        unordered_map<int, vector<pair<int, int>>> col_values;
        initPos(root, 0, 0, col_values);
        int l = INT_MAX;
        int r = INT_MIN;
        for (const auto &item: col_values) {
            l = min(l, item.first);
            r = max(r, item.first);
        }
        vector<vector<int>> ans;
        ans.reserve(col_values.size());
        for (auto i = l; i <= r; ++i) {
            if (!col_values.count(i)) {
                continue;
            }
            auto &col = col_values[i];
            sort(col.begin(), col.end());
            vector<int> cur;
            cur.reserve(col.size());
            for (const auto &x: col) {
                cur.emplace_back(x.second);
            }
            ans.emplace_back(cur);
        }
        return ans;
    }

private:
    void initPos(TreeNode *root, int sx, int sy, unordered_map<int, vector<pair<int, int>>> &col_values) {
        col_values[sy].push_back({sx, root->val});
        if (root->left) {  // 左节点坐标：(sx+1,sy-1)
            initPos(root->left, sx + 1, sy - 1, col_values);
        }
        if (root->right) {  // 右节点坐标：(sx+1,sy+1)
            initPos(root->right, sx + 1, sy + 1, col_values);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0987_H
