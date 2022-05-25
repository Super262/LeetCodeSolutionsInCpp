//
// Created by Fengwei Zhang on 5/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0369_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0369_H

#include "listnode.h"

class Solution {
    // 翻转链表，给低位加1；类似大整数加法，依次进位；然后再翻转链表，使高位为首位
public:
    ListNode *plusOne(ListNode *head) {
        if (!head) {
            return head;
        }
        head = reverseList(head);
        auto dummy = new ListNode(-1, head);
        int t = 1;
        auto cur = dummy;
        while (cur->next || t) {
            if (cur->next) {
                t += cur->next->val;
                cur->next->val = t % 10;
            } else {
                cur->next = new ListNode(t % 10);
            }
            t /= 10;
            cur = cur->next;
        }
        head = reverseList(dummy->next);
        delete dummy;
        return head;
    }

private:
    ListNode *reverseList(ListNode *head) {
        ListNode *a = nullptr;
        auto b = head;
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        return a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0369_H
