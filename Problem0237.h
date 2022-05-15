//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0237_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0237_H

#include "listnode.h"

class Solution {
public:
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0237_H
