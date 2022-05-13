//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0145_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0145_H

#include <vector>
#include <stack>
#include "treenode.h"

using namespace std;

class Solution {
    // Morris遍历，空间O(1)
    // 经典算法，直接背诵
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        TreeNode *p1 = root;
        while (p1) {
            auto p2 = p1->left;
            if (p2) {
                while (p2->right && p2->right != p1) {
                    p2 = p2->right;
                }
                if (!p2->right) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                    addPath(res, p1->left);
                }
            }
            p1 = p1->right;
        }
        addPath(res, root);
        return res;
    }

private:
    void addPath(vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node) {
            ++count;
            vec.emplace_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }
};

/*class Solution {
    // 经典算法，直接背诵
    // 巧妙做法：按照前序遍历，先右后左，再翻转结果
    // 空间O(n)
public:
    vector<int> postorderTraversal(TreeNode *root) {
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
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0145_H
