//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0117_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0117_H

#include "node_random.h"

class Solution {
    // 相比满二叉树（116题），这里的非叶节点可能只有1个孩子，因此我们需要一个tail指针来保存上个邻居的位置
    // 为统一操作，我们引入dummy为伪头节点
public:
    Node *connect(Node *root) {
        auto current = root;
        auto dummy = new Node(-1);
        while (current) {
            dummy->next = nullptr;
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
        delete dummy;
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0117_H
