//
// Created by Fengwei Zhang on 7/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_NODE_LIST_H
#define LEETCODESOLUTIONSINCPP_NODE_LIST_H

class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_NODE_LIST_H
