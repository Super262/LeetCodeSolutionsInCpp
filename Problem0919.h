//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0919_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0919_H

#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
    // BFS，用队列存储所有未满节点，队列的特性保证节点顺序是自左向右；自左向右插入新节点，并弹出已满节点
public:
    CBTInserter(TreeNode *root) {
        this->root = root;
        queue<TreeNode *> q;
        q.emplace(this->root);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (!u->left || !u->right) {  // 未满节点
                selectable.emplace(u);
            }
            if (u->left) {
                q.emplace(u->left);
            }
            if (u->right) {
                q.emplace(u->right);
            }
        }
    }

    int insert(int val) {
        auto u = selectable.front();
        if (!u->left) {
            u->left = new TreeNode(val);
            selectable.emplace(u->left);
        } else {
            u->right = new TreeNode(val);
            selectable.emplace(u->right);
            selectable.pop();
        }
        return u->val;
    }

    TreeNode *get_root() {
        return root;
    }

private:
    TreeNode *root;
    queue<TreeNode *> selectable;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0919_H
