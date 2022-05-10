//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0021_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0021_H

#include "listnode.h"

class Solution {
    // 经典算法，直接背诵；常用技巧：建立伪头（dummy）
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                auto t = l1;
                l1 = l1->next;
                t->next = nullptr;
                cur->next = t;
            } else {
                auto t = l2;
                l2 = l2->next;
                t->next = nullptr;
                cur->next = t;
            }
            cur = cur->next;
        }
        while (l1) {
            auto t = l1;
            l1 = l1->next;
            t->next = nullptr;
            cur->next = t;
            cur = cur->next;
        }
        while (l2) {
            auto t = l2;
            l2 = l2->next;
            t->next = nullptr;
            cur->next = t;
            cur = cur->next;
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0021_H
