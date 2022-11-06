//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0144_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0144_H

#include <stack>
#include <vector>
#include "treenode.h"

using namespace std;

class Problem0144 {
    // Morris遍历，直接背诵
    // 空间复杂度：O(1)
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        while (root) {
            auto p = root->left;
            if (p) {
                while (p->right && p->right != root) {
                    p = p->right;
                }
                if (!p->right) {
                    res.emplace_back(root->val);
                    p->right = root;
                    root = root->left;
                    continue;
                } else {
                    p->right = nullptr;
                }
            } else {
                res.emplace_back(root->val);
            }
            root = root->right;
        }
        return res;
    }
};

/*class Solution {
    // 经典算法，直接背诵
    // 空间复杂度：O(n)
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
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0144_H
