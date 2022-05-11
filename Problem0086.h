//
// Created by Fengwei Zhang on 10/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0086_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0086_H

#include "listnode.h"

class Solution {
    // 经典算法，直接背诵
public:
    ListNode *partition(ListNode *head, int x) {
        auto lh = new ListNode(-1);
        auto rh = new ListNode(-1);
        auto lt = lh;
        auto rt = rh;
        for (auto p = head; p; p = p->next) {
            if (p->val < x) {
                lt->next = p;
                lt = lt->next;
            } else {
                rt->next = p;
                rt = rt->next;
            }
        }
        lt->next = rh->next;
        rt->next = nullptr;
        return lh->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0086_H
