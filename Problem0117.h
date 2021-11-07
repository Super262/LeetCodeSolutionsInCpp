//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0117_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0117_H

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

class Problem0117 {
public:
    Node *connect(Node *root) {
        auto current = root;
        while (current) {
            auto dummy = new Node(-1);
            auto tail = dummy;
            for (auto p = current; p; p = p->next) {
                if (p->left) {
                    tail->next = p->left;
                    tail = tail->next;
                }
                if (p->right) {
                    tail->next = p->right;
                    tail = tail->next;
                }
            }
            current = dummy->next;
        }
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0117_H
