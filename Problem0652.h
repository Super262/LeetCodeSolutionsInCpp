//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0652_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0652_H

#include <vector>
#include <string>
#include <unordered_map>
#include "treenode.h"

using namespace std;

class Solution {
    // 先序遍历，反序列化当前树为字符串key，逗号分隔节点值，空节点值为"#"
    // 若key第二次出现，我们将当前树加入答案
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        vector<TreeNode *> ans;
        unordered_map<string, int> counter;
        dfs(root, counter, ans);
        return ans;
    }

private:
    string dfs(TreeNode *root,
               unordered_map<string, int> &counter,
               vector<TreeNode *> &ans) {
        if (!root) {
            return "#";
        }
        auto key = to_string(root->val) + "," + dfs(root->left, counter, ans) + "," + dfs(root->right, counter, ans);
        if (counter.count(key) && counter[key] == 1) {
            ans.emplace_back(root);
        }
        counter[key]++;
        return key;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0652_H
