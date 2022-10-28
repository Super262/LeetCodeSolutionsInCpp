//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0024_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0024_H

#include "listnode.h"

class Problem0024 {
public:
    ListNode *swapPairs(ListNode *head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy; p->next && p->next->next;) {
            auto a = p->next;
            auto b = a->next;
            a->next = b->next;
            b->next = a;
            p->next = b;
            p = a;
        }
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0024_H
