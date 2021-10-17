//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0160_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0160_H

class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        auto p1 = headA;
        auto p2 = headB;
        while (p1 || p2) {
            if (!p1) {
                p1 = headB;
            }
            if (!p2) {
                p2 = headA;
            }
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0160_H
