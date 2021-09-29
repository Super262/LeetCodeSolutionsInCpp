//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0019_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0019_H

class Problem0019 {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) {
            return head;
        }
        auto left = head; // the slow pointer
        auto right = head; // the fast pointer
        ++n;  // Increase n to get prev of nth node
        while (n > 0 && right) {  // The fast pointer moves
            right = right->next;
            --n;
        }
        if (n > 0) {  // n == sz, remove the head
            head = head->next;
            return head;
        }
        while (right) {  // Two ones move together
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        return head;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0019_H
