//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0426_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0426_H

#include "node_random.h"

class Solution {
    // 类似中序遍历，有序遍历BST的每个节点，并连接双链表
    // 细节：inOrder函数的参数是指针的引用；中序遍历结束后，要及时连接头、尾
public:
    Node *treeToDoublyList(Node *root) {
        if (!root) {
            return root;
        }
        Node *head = nullptr;
        Node *tail = nullptr;
        inOrder(root, head, tail);
        head->left = tail;
        tail->right = head;
        return head;
    }

private:
    void inOrder(Node *root, Node *&head, Node *&tail) {
        if (!root) {
            return;
        }
        inOrder(root->left, head, tail);
        if (tail) {
            tail->right = root;
        } else {
            head = root;
        }
        root->left = tail;
        tail = root;
        inOrder(root->right, head, tail);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0426_H
