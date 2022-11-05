//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0082_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0082_H

#include "listnode.h"

class Problem0082 {
    // 经典算法，直接背诵
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        auto dummy = new ListNode(-1, head);
        auto p = dummy;
        while (p->next) {
            auto q = p->next->next;
            while (q && q->val == p->next->val) {
                q = q->next;
            }
            if (p->next->next == q) {
                p = p->next;
            } else {
                p->next = q;
            }
        }
        return dummy->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0082_H
