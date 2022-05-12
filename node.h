//
// Created by Fengwei Zhang on 5/12/22.
//

#ifndef LEETCODESOLUTIONSINCPP_NODE_H
#define LEETCODESOLUTIONSINCPP_NODE_H

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

#endif //LEETCODESOLUTIONSINCPP_NODE_H
