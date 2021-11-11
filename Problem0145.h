//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0145_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0145_H

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

class Problem0145 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // 巧妙做法：按照前序遍历，先右后左；再翻转结果
        vector<int> res;
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                res.emplace_back(root->val);
                stk.emplace(root);
                root = root->right;
            }
            root = stk.top()->left;
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0145_H
