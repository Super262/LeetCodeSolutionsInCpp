//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0971_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0971_H

#include <vector>
#include <unordered_map>

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
    // 预处理每个值对应的索引
    // 先序遍历：第1个值输出自根节点；递归处理，尝试交换
public:
    vector<int> flipMatchVoyage(TreeNode *root, const vector<int> &vals) {
        unordered_map<int, int> idx;
        for (int i = 0; i < (int) vals.size(); ++i) {
            idx[vals[i]] = i;
        }
        vector<int> ans;
        if (!dfs(root, vals, 0, (int) vals.size() - 1, idx, ans)) {
            return {-1};
        }
        return ans;
    }

private:
    bool dfs(TreeNode *u, const vector<int> &vals, int st, int ed, unordered_map<int, int> &idx, vector<int> &ans) {
        if (!u) {  // 节点不存在，序列应为空
            return st > ed;
        }
        if (st > ed || u->val != vals[st]) {  // 节点存在，但序列不合法
            return false;
        }
        if (!u->left && !u->right) {  // 只有根结点
            return ed == st && u->val == vals[st];
        }
        if (u->left && u->right) {  // 左、右子树都存在
            auto lvi = idx[u->left->val];
            auto rvi = idx[u->right->val];
            if (lvi == st + 1) {  // 左树在前，尝试不交换
                return dfs(u->left, vals, lvi, rvi - 1, idx, ans) &&
                       dfs(u->right, vals, rvi, ed, idx, ans);
            }
            if (rvi == st + 1) {  // 右树在前，尝试交换
                if (dfs(u->left, vals, lvi, ed, idx, ans) &&
                    dfs(u->right, vals, rvi, lvi - 1, idx, ans)) {
                    ans.emplace_back(u->val);
                    return true;
                }
                return false;
            }
            return false;
        }
        if (u->left) {  // 只存在左子树
            return idx[u->left->val] == st + 1 && dfs(u->left, vals, st + 1, ed, idx, ans);
        }
        // 只存在右子树
        return idx[u->right->val] == st + 1 && dfs(u->right, vals, st + 1, ed, idx, ans);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0971_H
