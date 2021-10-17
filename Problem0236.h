//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0236_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0236_H

class Problem0236 {  // 牢记LCA算法
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q) {
            return NULL;
        }
        if (p == root || q == root) {
            return root;
        }
        auto leftResult = lowestCommonAncestor(root->left, p, q);  // 向左查找包含p或q的子树
        auto rightResult = lowestCommonAncestor(root->right, p, q);  // 向右查找包含p或q的子树
        if (leftResult && rightResult) {
            return root;
        }
        if (leftResult) {
            return leftResult;
        }
        return rightResult;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0236_H
