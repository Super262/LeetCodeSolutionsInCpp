//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0019_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0019_H

#include "listnode.h"

class Problem0019 {
    // 经典算法，直接背诵：找到第n个节点的前驱，删除第n个节点
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ++n;  // Increase n to make "l" can get the prev of nth node
        auto l = head;  // the slow pointer
        auto r = head;  // the fast pointer
        while (n > 0 && r) {
            --n;
            r = r->next;
        }
        if (n > 0) {  // n == sz, remove the head
            auto t = head->next;
            delete head;
            head = t;
            return head;
        }
        while (r) {  // Two pointers move together
            l = l->next;
            r = r->next;
        }
        auto t = l->next->next;
        delete l->next;
        l->next = t;
        return head;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0019_H
