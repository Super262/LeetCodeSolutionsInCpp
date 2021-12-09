//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0426_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0426_H


class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (!root) {
            return root;
        }
        Node *head = nullptr;
        Node *tail = nullptr;
        in_order(root, head, tail);
        head->left = tail;
        tail->right = head;
        return head;
    }

private:
    void in_order(Node *root, Node *&head, Node *&tail) {
        if (!root) {
            return;
        }
        in_order(root->left, head, tail);
        if (tail) {
            tail->right = root;
        } else {
            head = root;
        }
        root->left = tail;
        tail = root;
        in_order(root->right, head, tail);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0426_H
