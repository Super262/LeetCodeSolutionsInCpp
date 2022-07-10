//
// Created by Fengwei Zhang on 6/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0510_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0510_H

#include "node_parent.h"

class Solution {
    // 根据题意，我们要寻找node在中序遍历下的后继节点
    // 若node有右子树，结果应是node->right的最左节点；若node无右子树，则node的后继应是node右上方的祖先节点
public:
    Node *inorderSuccessor(Node *node) {
        if (!node) {
            return nullptr;
        }
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        }
        while (node->parent && node != node->parent->left) {
            node = node->parent;
        }
        return node->parent;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0510_H
