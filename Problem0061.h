//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0061_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0061_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem0061 {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {
            return head;
        }

        // Find the tail and get the length.
        int n = 0;
        ListNode *tail;
        for (auto p = head; p != NULL; p = p->next) {
            tail = p;
            ++n;
        }


        // Find the parent of Node K.
        k %= n;
        ListNode *prev = head;
        for (int i = 0; i < n - k - 1; ++i) {
            prev = prev->next;
        }

        // Rotate.
        tail->next = head;
        head = prev->next;
        prev->next = NULL;

        return head;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0061_H
