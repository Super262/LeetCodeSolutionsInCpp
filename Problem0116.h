//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0116_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0116_H

#include "node_random.h"

class Problem0116 {
    // 经典算法，直接背诵
    // 注意：输入是满二叉树
public:
    Node *connect(Node *root) {
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
