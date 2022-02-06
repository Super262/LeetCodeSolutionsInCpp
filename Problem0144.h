//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0144_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0144_H

#include <stack>
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

class Solution {
    // Morris遍历，直接背诵
    // 空间复杂度：O(1)
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        TreeNode *p1 = root;
        vector<int> res;
        while (p1) {
            auto p2 = p1->left;
            if (p2) {
                while (p2->right && p2->right != p1) {
                    p2 = p2->right;
                }
                if (!p2->right) {
                    res.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                }
            } else {
                res.emplace_back(p1->val);
            }
            p1 = p1->right;
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
