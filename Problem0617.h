//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0617_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0617_H

#include <algorithm>

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
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t2) {  // 技巧：保证t1非空，简化操作
            swap(t1, t2);
        }
        if (!t1) {
            return nullptr;
        }
        if (t2) {
            t1->val += t2->val;
        }
        t1->left = mergeTrees(t1->left, t2 ? t2->left : nullptr);
        t1->right = mergeTrees(t1->right, t2 ? t2->right : nullptr);
        return t1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0617_H
