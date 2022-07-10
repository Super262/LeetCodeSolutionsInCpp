//
// Created by Fengwei Zhang on 5/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_NODE_NARY_H
#define LEETCODESOLUTIONSINCPP_NODE_NARY_H

#include <vector>

class Node {
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

#endif //LEETCODESOLUTIONSINCPP_NODE_NARY_H
