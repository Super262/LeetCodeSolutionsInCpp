//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0203_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0203_H

#include "listnode.h"

class Solution {
    // 引入dummy伪头节点，简化操作
public:
    ListNode *removeElements(ListNode *head, const int &val) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0203_H
