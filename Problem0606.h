//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0606_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0606_H

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0606_H

#include <string>
#include "treenode.h"

using namespace std;

class Solution {
    // 类似先序遍历
    // 细节：左子树为空，右子树不空，不能省略空括号
public:
    string tree2str(TreeNode *root) {
        string ans;
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, string &ans) {
        if (!root) {
            return;
        }
        ans += to_string(root->val);
        if (root->left || root->right) {
            ans += '(';
            dfs(root->left, ans);
            ans += ')';
        }
        if (root->right) {
            ans += '(';
            dfs(root->right, ans);
            ans += ')';
        }
    }
};