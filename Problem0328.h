//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0328_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0328_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        auto oddHead = head;
        auto evenHead = head->next;
        auto oddTail = oddHead;
        auto evenTail = evenHead;
        for (auto p = head->next->next; p; p = p->next) {
            oddTail->next = p;
            oddTail = p;
            if (p->next) {
                p = p->next;
                evenTail->next = p;
                evenTail = p;
            }
        }
        oddTail->next = evenHead;
        evenTail->next = nullptr;
        return oddHead;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0328_H
