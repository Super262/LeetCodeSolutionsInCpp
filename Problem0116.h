//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0116_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0116_H

#include <algorithm>

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) { // 注意：输入是满二叉树
        if (!root) {
            return root;
        }
        auto current = root;
        while (current->left) { // 下一层存在
            for (auto p = current; p; p = p->next) { // 处理下一层
                p->left->next = p->right;
                if (p->next) {
                    p->right->next = p->next->left;
                }
            }
            current = current->left;
        }
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0116_H
