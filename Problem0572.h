//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0572_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0572_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 完全线性的解法：树上哈希，类似字符串，以质数为基数
    // H(root) = (H(root->val) + H(root->left) * P % MOD + H(root->right) * Q % MOD) % MOD;
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        int t = -1;
        bool answer = false;
        t = dfs(subRoot, t, answer);
        if (t == dfs(root, t, answer)) {
            answer = true;
        }
        return answer;
    }

private:
    const int P = 131, Q = 159, MOD = 1e9 + 7;

    int dfs(TreeNode *root, const int t, bool &answer) {  // 计算哈希值，并查找有无子树哈希值为t
        if (!root) {
            return -2;
        }
        auto lh = dfs(root->left, t, answer);
        auto rh = dfs(root->right, t, answer);
        auto ph = (root->val % MOD + MOD) % MOD;
        if (lh == t || rh == t) {
            answer = true;
        }
        return (int) ((ph + (long long) lh * P % MOD + (long long) rh * Q % MOD) % MOD);
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0572_H
