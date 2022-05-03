//
// Created by Fengwei Zhang on 9/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0002_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0002_H

#include "listnode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto dummy = new ListNode(-1);
        auto current = dummy;
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
            current->next = new ListNode(t % 10);
            t /= 10;
            current = current->next;
        }
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0002_H
