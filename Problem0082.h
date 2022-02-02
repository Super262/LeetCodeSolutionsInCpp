//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0082_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0082_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
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
