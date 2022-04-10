//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0897_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0897_H

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

class Solution {
    // 在遍历的过程中向单链表插入新节点
    // 返回结果前，删除头节点，避免内存泄漏
public:
    TreeNode *increasingBST(TreeNode *root) {
        auto head = new TreeNode(-1);
        auto tail = head;
        inOrder(root, tail);
        auto ans = head->right;
        delete head;
        return ans;
    }

private:
    void inOrder(TreeNode *root, TreeNode *&tail) {
        if (!root) {
            return;
        }
        inOrder(root->left, tail);
        tail->right = root;
        tail = tail->right;
        tail->left = nullptr;
        inOrder(root->right, tail);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0897_H
