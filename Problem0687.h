//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0687_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0687_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
    // 后序遍历，设左子树中由根向下延伸的单值路径最长为l、右子树中由根向下延伸的单值路径最长为r
    // 若root->val不等于等于root->left->val，更新l=0；右子树同理；最终答案ans=max({l+r})
    // 细节：本题的路径长度是边的长度，不是节点个数
public:
    int longestUnivaluePath(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode *root, int &ans) {
        int l = 0;
        int r = 0;
        if (root->left) {
            l = dfs(root->left, ans);
            if (root->left->val != root->val) {
                l = 0;
            }
        }
        if (root->right) {
            r = dfs(root->right, ans);
            if (root->right->val != root->val) {
                r = 0;
            }
        }
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0687_H
