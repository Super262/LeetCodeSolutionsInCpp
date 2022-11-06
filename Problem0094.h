//
// Created by Fengwei Zhang on 10/30/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0094_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0094_H

#include <vector>
#include <stack>
#include "treenode.h"

using namespace std;

class Problem0094 {
    // 直接背诵，注意细节；面试前背诵Morris遍历
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            if (!stk.empty()) {
                root = stk.top();
                stk.pop();
                ans.emplace_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0094_H
