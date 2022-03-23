//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0019_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0019_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 经典算法，直接背诵
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
