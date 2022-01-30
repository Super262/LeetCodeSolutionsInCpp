//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0024_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0024_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
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
        return dummy->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0024_H
