//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0019_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0019_H

#include "listnode.h"

class Solution {
    // 经典算法，直接背诵：找到第n个节点的前驱，删除第n个节点
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) {
            return head;
        }
        auto l = head; // the slow pointer
        auto r = head; // the fast pointer
        ++n;  // Increase n to make "l" can get the prev of nth node
        while (n > 0 && r) {  // The fast pointer moves
            r = r->next;
            --n;
        }
        if (n > 0) {  // n == sz, remove the head
            head = head->next;
            return head;
        }
        while (r) {  // Two pointers move together
            r = r->next;
            l = l->next;
        }
        l->next = l->next->next;
        return head;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0019_H
