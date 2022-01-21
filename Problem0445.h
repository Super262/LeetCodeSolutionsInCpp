//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0445_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0445_H


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        auto head = new ListNode(-1);
        int t = 0;
        while (l1 || l2 || t) {
            if (l1) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                t += l2->val;
                l2 = l2->next;
            }
            auto cur = new ListNode(t % 10);
            t /= 10;
            cur->next = head->next;
            head->next = cur;
        }
        return head->next;
    }

private:
    ListNode *reverseList(ListNode *l) {
        if (!l->next) {
            return l;
        }
        ListNode *a = nullptr;
        auto b = l;
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        return a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0445_H
