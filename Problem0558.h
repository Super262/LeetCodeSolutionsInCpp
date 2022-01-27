//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0558_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0558_H

#include <algorithm>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node *intersect(Node *t1, Node *t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
        if (t1->isLeaf) {
            return t1->val ? t1 : t2;
        }
        if (t2->isLeaf) {
            return t2->val ? t2 : t1;
        }
        t1->topLeft = intersect(t1->topLeft, t2->topLeft);
        t1->bottomLeft = intersect(t1->bottomLeft, t2->bottomLeft);
        t1->topRight = intersect(t1->topRight, t2->topRight);
        t1->bottomRight = intersect(t1->bottomRight, t2->bottomRight);
        if (t1->topLeft->isLeaf && t1->topRight->isLeaf && t1->bottomLeft->isLeaf && t1->bottomRight->isLeaf) {
            if (t1->topLeft->val == t1->topRight->val && t1->topRight->val == t1->bottomLeft->val &&
                t1->bottomLeft->val == t1->bottomRight->val) {
                t1->isLeaf = true;
                t1->val = t1->topLeft->val;
                t1->topLeft = NULL;
                t1->topRight = NULL;
                t1->bottomLeft = NULL;
                t1->bottomRight = NULL;
            }
        }
        return t1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0558_H
