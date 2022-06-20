//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0572_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0572_H

#include "treenode.h"

class Solution {
    // 完全线性的解法：树上哈希，类似字符串，以质数为基数
    // 哈希公式：H(root) = (H(root->val) + H(root->left) * P % MOD + H(root->right) * Q % MOD) % MOD；空树哈希值为-2
    // 类似后序遍历，先计算左、右子树的哈希值，再计算当前树的哈希值，计算完成后将其和t比较
public:
    bool isSubtree(TreeNode *root, TreeNode *sub_root) {
        bool ans = false;
        auto t = dfs(sub_root, -1, ans);  // 获得sub_root的哈希值
        if (t == dfs(root, t, ans)) {  // root和sub_root相等
            return true;
        }
        return ans;
    }

private:
    const int P = 131, Q = 159, MOD = 1e9 + 7;

    int dfs(TreeNode *root, const int t, bool &ans) {  // 计算哈希值，并查找有无子树哈希值为t
        if (!root) {
            return -2;
        }
        auto lh = dfs(root->left, t, ans);
        auto rh = dfs(root->right, t, ans);
        auto ph = (root->val % MOD + MOD) % MOD;
        if (lh == t || rh == t) {
            ans = true;
        }
        return (int) ((ph + (long long) lh * P % MOD + (long long) rh * Q % MOD) % MOD);
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0572_H
