//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0559_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0559_H

#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node *root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        for (const auto &t: root->children) {
            res = max(res, maxDepth(t));
        }
        return res + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0559_H
