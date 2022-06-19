//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0558_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0558_H

#include <algorithm>
#include "quad_node.h"

using namespace std;

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
                t1->topLeft = nullptr;
                t1->topRight = nullptr;
                t1->bottomLeft = nullptr;
                t1->bottomRight = nullptr;
            }
        }
        return t1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0558_H
