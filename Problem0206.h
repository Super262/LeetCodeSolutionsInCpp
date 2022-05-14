//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0206_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0206_H

#include "listnode.h"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head) {
            return head;
        }
        auto a = head;
        auto b = head->next;
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        head->next = nullptr;
        return a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0206_H
