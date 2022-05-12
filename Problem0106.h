//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0106_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0106_H

#include <stack>
#include <unordered_map>
#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
    // 非递归方法，必须掌握
    // https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/cong-zhong-xu-yu-hou-xu-bian-li-xu-lie-gou-zao-14/
public:
    TreeNode *buildTree(const vector<int> &inorder, const vector<int> &postorder) {
        if (postorder.empty()) {
            return nullptr;
        }
        auto root = new TreeNode(postorder.back());
        stack<TreeNode *> stk;
        stk.emplace(root);
        auto ino_idx = (int) inorder.size() - 1;
        for (auto i = (int) postorder.size() - 2; i >= 0; i--) {
            auto val = postorder[i];
            auto node = stk.top();
            if (node->val != inorder[ino_idx]) {
                node->right = new TreeNode(val);
                stk.emplace(node->right);
                continue;
            }
            while (!stk.empty() && stk.top()->val == inorder[ino_idx]) {
                node = stk.top();
                stk.pop();
                --ino_idx;
            }
            node->left = new TreeNode(val);
            stk.emplace(node->left);
        }
        return root;
    }
};

/*class Solution {
    // 递归方法，必须掌握
public:
    TreeNode *buildTree(const vector<int> &inorder, const vector<int> &postorder) {
        unordered_map<int, int> in_order_pos;
        for (int i = 0; i < (int) inorder.size(); ++i) {
            in_order_pos[inorder[i]] = i;
        }
        return helper(postorder, inorder, in_order_pos, 0, (int) postorder.size() - 1, 0, (int) inorder.size() - 1);
    }

private:
    TreeNode *helper(const vector<int> &postorder,
                     const vector<int> &inorder,
                     const unordered_map<int, int> &in_order_pos,
                     const int pl,
                     const int pr,
                     const int il,
                     const int ir) {
        if (il > ir) {
            return nullptr;
        }
        auto root = new TreeNode(postorder[pr]);
        auto mid = in_order_pos.find(postorder[pr])->second;
        root->left = helper(postorder, inorder, in_order_pos, pl, pl + (mid - il) - 1, il, mid - 1);
        root->right = helper(postorder, inorder, in_order_pos, pl + (mid - il), pr - 1, mid + 1, ir);
        return root;
    }
};*/


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0106_H
