//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0144_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0144_H

#include <stack>

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                result.emplace_back(root->val);
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top()->right;
            stk.pop();
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0144_H
