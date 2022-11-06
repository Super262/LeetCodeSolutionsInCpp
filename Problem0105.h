//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0105_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0105_H

#include <stack>
#include <unordered_map>
#include <vector>
#include "treenode.h"

using namespace std;

class Problem0105 {
    // 非递归方法，必须掌握
    // https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou-zao-9/
public:
    TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        auto *root = new TreeNode(preorder[0]);
        int inorder_idx = 0;  // 当前节点不断往左走达到的最终节点
        stack<TreeNode *> stk;  // 当前节点的所有还没有考虑过右儿子的祖先节点
        stk.emplace(root);
        for (int i = 1; i < (int) preorder.size(); ++i) {
            auto value = preorder[i];
            auto *node = stk.top();
            if (node->val != inorder[inorder_idx]) {
                node->left = new TreeNode(value);
                stk.emplace(node->left);
                continue;
            }
            while (!stk.empty() && stk.top()->val == inorder[inorder_idx]) {
                node = stk.top();
                stk.pop();
                ++inorder_idx;
            }
            node->right = new TreeNode(value);
            stk.emplace(node->right);
        }
        return root;
    }
};

/*class Solution {
    // 递归方法，必须掌握
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> in_order_pos;
        for (int i = 0; i < (int) inorder.size(); ++i) {
            in_order_pos[inorder[i]] = i;
        }
        return helper(preorder, inorder, in_order_pos, 0, (int) preorder.size() - 1, 0, (int) inorder.size() - 1);
    }

private:
    TreeNode *helper(const vector<int> &preorder,
                     const vector<int> &inorder,
                     const unordered_map<int, int> &in_order_pos,
                     const int pl,
                     const int pr,
                     const int il,
                     const int ir) {
        if (il > ir) {
            return nullptr;
        }
        auto root = new TreeNode(preorder[pl]);
        auto mid = in_order_pos.find(preorder[pl])->second;
        root->left = helper(preorder, inorder, in_order_pos, pl + 1, pl + mid - il, il, mid - 1);
        root->right = helper(preorder, inorder, in_order_pos, pr - (ir - mid) + 1, pr, mid + 1, ir);
        return root;
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0105_H
