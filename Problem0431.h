//
// Created by Fengwei Zhang on 5/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0431_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0431_H

#include <queue>
#include "treenode.h"
#include "nary_node.h"

using namespace std;

class Codec {
    // 多叉树转二叉树：子节点用右指针构成单链表，根结点的左指针指向第1个子节点；层序遍历，逐层操作
    // https://en.wikipedia.org/wiki/M-ary_tree#Convert_a_m-ary_tree_to_binary_tree
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode *encode(Node *root) {
        if (!root) {
            return nullptr;
        }
        auto ans = new TreeNode(root->val);
        queue<pair<Node *, TreeNode *>> q;
        auto dummy = new TreeNode(-1);
        q.emplace(root, ans);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            dummy->right = nullptr;
            auto cur = dummy;
            for (const auto &kid: t.first->children) {
                cur->right = new TreeNode(kid->val);
                q.emplace(kid, cur->right);
                cur = cur->right;
            }
            t.second->left = dummy->right;
        }
        delete dummy;
        return ans;
    }

    // Decodes your binary tree to an n-ary tree.
    Node *decode(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        auto ans = new Node(root->val, vector<Node *>());
        queue<pair<TreeNode *, Node *>> q;
        q.emplace(root, ans);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (auto cur = t.first->left; cur; cur = cur->right) {
                auto kid = new Node(cur->val, vector<Node *>());
                t.second->children.emplace_back(kid);
                q.emplace(cur, kid);
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0431_H
