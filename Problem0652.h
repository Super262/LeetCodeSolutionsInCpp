//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0652_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0652_H

#include <vector>
#include <string>
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
    // 经典算法，直接背诵：对每棵子树通过递归的方式映射到一个字符串
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        vector<TreeNode *> res;
        unordered_map<string, int> ids;  // 映射：(字符串, 整数)
        unordered_map<int, int> counter;  // 记录每个id的频率
        int idx = 1;  // 有效id从1开始
        dfs(root, idx, ids, counter, res);
        return res;
    }

private:
    int dfs(TreeNode *root,
            int &idx,
            unordered_map<string, int> &ids,
            unordered_map<int, int> &counter,
            vector<TreeNode *> &res) {
        if (!root) {  // 无效id为0
            return 0;
        }
        auto l = dfs(root->left, idx, ids, counter, res);
        auto r = dfs(root->right, idx, ids, counter, res);
        auto key = to_string(l) + ' ' + to_string(root->val) + ' ' + to_string(r);
        if (!ids.count(key)) {
            ids[key] = idx;
            ++idx;
        }
        auto k = ids[key];
        ++counter[k];
        if (counter[k] == 2) {  // 为避免重复，只有当频率恰好为2时添加根到结果集
            res.emplace_back(root);
        }
        return k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0652_H
