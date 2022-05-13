//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0160_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0160_H

#include "listnode.h"

class Solution {
    // 直接背诵：p1、p2同时移动，当某个指针移动到末尾后，让它在另一条链上继续移动，直到两者相遇
public:
    ListNode *getIntersectionNode(ListNode *head_a, ListNode *head_b) {
        if (!head_a || !head_b) {
            return nullptr;
        }
        auto p1 = head_a;
        auto p2 = head_b;
        while (p1 || p2) {
            if (!p1) {
                p1 = head_b;
            }
            if (!p2) {
                p2 = head_a;
            }
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0160_H
