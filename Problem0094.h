//
// Created by Fengwei Zhang on 10/30/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0094_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0094_H

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0094 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack < TreeNode * > stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            if (!stk.empty()) {
                root = stk.top();
                res.emplace_back(root->val);
                stk.pop();
                root = root->right;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0094_H
