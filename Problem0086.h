//
// Created by Fengwei Zhang on 10/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0086_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0086_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem0086 {
public:
    ListNode *partition(ListNode *head, int x) {
        auto lh = new ListNode(-1);
        auto rh = new ListNode(-1);
        auto lt = lh, rt = rh;
        for (auto p = head; p; p = p->next) {
            if (p->val < x) {
                lt->next = p;
                lt = lt->next;
            } else {
                rt->next = p;
                rt = rt->next;
            }
        }
        lt->next = rh->next;
        rt->next = NULL;
        return lh->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0086_H
